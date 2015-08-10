#include "documentviewer.h"
#include "ui_documentviewer.h"
#include <fstream>
#include <QDebug>

documentViewer::documentViewer(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::documentViewer();
	ui->setupUi(this);
	
}

documentViewer::~documentViewer()
{
	delete ui;
	
}

void documentViewer::on_boxID_textChanged(const QString & text){
	bool ok;
	int id=text.toInt(&ok);
	if(!ok){
		ui->boxDocument->setText("Please input an integer, as the ID for the wanted document.\n");
		return;
	}
	auto search = documents.find(id);
	if(search != documents.end()) {
		std::ifstream input(fileName);
		std::string title, content;
		input.seekg(search->second);
		getline(input, title);
		getline(input, title);
		getline(input, content);
		if(input.bad()){
			ui->boxDocument->setText("<b>Document ID</b>:<br>"+QString::number(id)+"<hr>Error occured when reading the file.\n");
		}
			
		
		QString displayHTML="<b>Document ID</b>:<br>"+QString::number(id)+"<hr><b>Title</b>:<br>"+QString::fromStdString(title)+"<hr><b>Content</b>:<br>"+QString::fromStdString(content);
		ui->boxDocument->setText(displayHTML);
	}
	else {
		ui->boxDocument->setText("Document with ID "+QString::number(id)+" is not found.\n");
	}

}
void documentViewer::loadData(){
	documents.clear();
	std::ifstream input(fileName);
	while(!input.eof()){
		int n;
		input >> n;

		if (input.eof() || input.bad()) {
			break;
			
		}/*else if (input.fail()) {
			input.clear(); // unset failbit
			input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
		} else*/{
			//qDebug() << n << input.tellg() << '\n';
			documents.emplace(n, input.tellg());
			input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
			input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
			input.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
		}
		
	}
	input.close();
}
