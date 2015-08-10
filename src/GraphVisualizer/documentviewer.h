#ifndef DOCUMENTVIEWER_H
#define DOCUMENTVIEWER_H

#include <QMainWindow>
#include <map>
#include <QMessageBox>
namespace Ui {class documentViewer;};

class documentViewer : public QMainWindow
{
	Q_OBJECT
	
public:
	std::string fileName;
	std::map<int, int> documents;
	documentViewer(QWidget *parent = 0);
	~documentViewer();
	void setFileName(std::string fileName_){
		fileName=fileName_;
		loadData();
	}

public slots:
	void on_boxID_textChanged(const QString & text);

private:
	
	void loadData();

	Ui::documentViewer *ui;
};

#endif // DOCUMENTVIEWER_H
