#ifndef GRAPHVISUALIZER_H
#define GRAPHVISUALIZER_H

#include "Graph.h"
#include "ui_graphvisualizer.h"
#include "documentviewer.h"
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QProgressDialog>
#include <QTime>
#include <QTimer>
#include <QtWidgets/QMainWindow>
#include <cstdlib>
#include <set>
using std::rand;
using std::set;

#define FILENAME_TGDC "TopicGraph\\DocumentContent.txt"
#define FILENAME_TGN  "TopicGraph\\nodes.txt"
#define FILENAME_TGE  "TopicGraph\\edges.txt"
#define FILENAME_PCAN "PaperConferenceAuthorGraph\\nodes.txt"
#define FILENAME_PCAE "PaperConferenceAuthorGraph\\edges.txt"

//绘图时坐标换算
#define transformX(x) (((x)+viewCenterX)*viewScale)
#define transformY(y) (((y)+viewCenterY)*viewScale)
#define transformR(r) ((int)((r)*viewScale))

#define f(b,a,c) (a-c<=b && b<=a+c) // arg1 in range(arg2 +- arg3)

//节点边框颜色
#define COLOR_NODE_EDGE_FILTERED		Qt::PenStyle::NoPen
#define COLOR_NODE_EDGE_NORMAL			Qt::PenStyle::DotLine


class GraphVisualizer : public QMainWindow
{
	Q_OBJECT
		
private:
	//节点填充
		QColor  COLOR_NODE_PAPER				;
		QColor  COLOR_NODE_AUTHOR				;
		QColor  COLOR_NODE_CONFERENCE			;

		QColor  COLOR_NODE_NORMAL				;
		QColor  COLOR_NODE_FILTERED				;
		QColor  COLOR_NODE_MOUSEOVER			;
		QColor  COLOR_NODE_CLICKED				;
		QColor  COLOR_NODE_DRAGGING				;
		QColor  COLOR_NODE_HIGHLIGHTED			;

	//边颜色
		QColor  COLOR_EDGE_NORMAL			    ;
		QColor  COLOR_EDGE_FILTERED				;
		QColor  COLOR_EDGE_HIGHLIGHTED			;
		QColor  COLOR_SELECT_BOX;

		QColor reverse(QColor c){
			QColor ret;
			int r, g, b, a;
			c.getRgb(&r, &g, &b, &a);
			ret.setRgb(255-r, 255-g, 255-b, a);
			return ret;
		}
		QColor randColor(){
			QColor ret;
			
			
			ret.setRgb(rand()%255,rand()%255,rand()%255,rand()%255);
			return ret;
		}
		void setTheme(int t){
			qDebug() << "set theme" << t;
			
			if(t==1){
				QPalette palette(this->palette());
				palette.setColor(QPalette::Background, QColor(240,240,240));
				palette.setColor(QPalette::WindowText, Qt::black);
				this->setPalette(palette);

				COLOR_SELECT_BOX = QColor(0,0,64,100);

				//节点填充
				COLOR_NODE_PAPER				=QColor(250,50,50,100);
				COLOR_NODE_AUTHOR				=QColor(50,250,50,100);
				COLOR_NODE_CONFERENCE			=QColor(50,50,250,100);

				COLOR_NODE_NORMAL				=QColor(50,50,50,100);
				COLOR_NODE_FILTERED				=QColor(200,200,200,25);
				COLOR_NODE_MOUSEOVER			=QColor(255,0,0,200);
				COLOR_NODE_CLICKED				=QColor(0,0,255,200);
				COLOR_NODE_DRAGGING				=QColor(128,0,128,200);
				COLOR_NODE_HIGHLIGHTED			=QColor(255,128,0,200);

				//边颜色
				COLOR_EDGE_NORMAL			    =QColor(50,50,50,200);
				COLOR_EDGE_FILTERED				=QColor(200,200,200,100);
				COLOR_EDGE_HIGHLIGHTED			=QColor(200,100,0,200);
			}else if(t==2){
				QPalette palette(this->palette());
				palette.setColor(QPalette::Background, Qt::black);
				palette.setColor(QPalette::WindowText, Qt::white);
				this->setPalette(palette);
				
				COLOR_SELECT_BOX = reverse(QColor(0,0,64,100));

				//节点填充
				COLOR_NODE_PAPER				=reverse(QColor(250,50,50,100));
				COLOR_NODE_AUTHOR				=reverse(QColor(50,250,50,100));
				COLOR_NODE_CONFERENCE			=reverse(QColor(50,50,250,100));

				COLOR_NODE_NORMAL				=reverse(QColor(50,50,50,100));
				COLOR_NODE_FILTERED				=reverse(QColor(200,200,200,25));
				COLOR_NODE_MOUSEOVER			=reverse(QColor(255,0,0,200));
				COLOR_NODE_CLICKED				=reverse(QColor(0,0,255,200));
				COLOR_NODE_DRAGGING				=reverse(QColor(128,0,128,200));
				COLOR_NODE_HIGHLIGHTED			=reverse(QColor(255,128,0,200));

				//边颜色
				COLOR_EDGE_NORMAL			    =reverse(QColor(50,50,50,200));
				COLOR_EDGE_FILTERED				=reverse(QColor(200,200,200,100));
				COLOR_EDGE_HIGHLIGHTED			=reverse(QColor(200,100,0,200));
			}else if(t==3){
				QPalette palette(this->palette());
				palette.setColor(QPalette::Background, (QColor(240,226,243)));
				palette.setColor(QPalette::WindowText, QColor(64,29,71));
				this->setPalette(palette);
				COLOR_SELECT_BOX = (QColor(223,193,230,100));
				//节点填充
				COLOR_NODE_PAPER				=(QColor(250,50,50,100));
				COLOR_NODE_AUTHOR				=(QColor(50,250,50,100));
				COLOR_NODE_CONFERENCE			=(QColor(50,50,250,100));

				COLOR_NODE_NORMAL				=(QColor(213,170,221,100));
				COLOR_NODE_FILTERED				=(QColor(220,187,227,25));
				COLOR_NODE_MOUSEOVER			=(QColor(99,45,111,200));
				COLOR_NODE_CLICKED				=(QColor(80,36,89,200));
				COLOR_NODE_DRAGGING				=(QColor(80,36,89,200));
				COLOR_NODE_HIGHLIGHTED			=(QColor(187,120,201,200));

				//边颜色
				COLOR_EDGE_NORMAL			    =(QColor(179,105,194,200));
				COLOR_EDGE_FILTERED				=(QColor(231,206,236,100));
				COLOR_EDGE_HIGHLIGHTED			=(QColor(129,58,143,200));
			}else if(1){
				QPalette palette(this->palette());
				palette.setColor(QPalette::Background, randColor());
				palette.setColor(QPalette::WindowText, randColor());
				this->setPalette(palette);
				
				COLOR_SELECT_BOX = randColor();
				//节点填充
				COLOR_NODE_PAPER				=randColor();
				COLOR_NODE_AUTHOR				=randColor();
				COLOR_NODE_CONFERENCE			=randColor();

				COLOR_NODE_NORMAL				=randColor();
				COLOR_NODE_FILTERED				=randColor();
				COLOR_NODE_MOUSEOVER			=randColor();
				COLOR_NODE_CLICKED				=randColor();
				COLOR_NODE_DRAGGING				=randColor();
				COLOR_NODE_HIGHLIGHTED			=randColor();

				//边颜色
				COLOR_EDGE_NORMAL			    =randColor();
				COLOR_EDGE_FILTERED				=randColor();
				COLOR_EDGE_HIGHLIGHTED			=randColor();
			}
		}
private:
	TopicGraph tGraph;
	PaperConferenceAuthorGraph pcaGraph;
	int whichGraphFlag; //1 for TopicGraph, 2 for PaperConferenceAuthorGraph
	int whichLayoutFlag; //1 for force, 2 for circular
	double viewCenterX, viewCenterY;
	double viewScale;
	int mouseX, mouseY;
	bool mouseDownFlag;

	QTimer *animationTimer;
	bool isAnimationGoingOn;
	double displayEdgeWidth;
	double displayNodeRadius;
	int displayMinDegree;
	int draggingNodeIndex;//-1 for none. index in vector topics or id in union nodes
	
	int clickedNodeIndex;//-1 for none. index in vector topics or id in union nodes
	set<Node*> selectedNodes;//id in either topics or union nodes
	set<int> selectedNodeIDs;//id in either topics or union nodes
	bool selectingFlag;
	bool selectingDraggingFlag;
	int selectStartX, selectStartY;
	QRect selectedRect(){
		return QRect(QPoint(selectStartX, selectStartY), QPoint(mouseX, mouseY));
	}

	int mouseOverNodeIndex;

	bool draggingFlag;
	int displayFontSize;
	int animationPhase;//动画相位，range [0,nAnimationPhase]
	static const int nAnimationPhase = 48;
public:
	documentViewer viewer;
	GraphVisualizer(QWidget *parent = 0);
	~GraphVisualizer();
	void init(){
		whichGraphFlag=0;
		whichLayoutFlag=0;
		viewCenterY=0;viewCenterX=0;viewScale=1.0;
		mouseX=0;mouseY=0;mouseDownFlag=0;
		isAnimationGoingOn=false;
		displayNodeRadius=2;displayMinDegree=0;displayEdgeWidth=1;
		draggingNodeIndex=-1;clickedNodeIndex=-1;
		draggingFlag=0;
		displayFontSize=12;
		ui.degreeSlider->setValue(0);
		ui.fontSizeSlider->setValue(12);
		ui.radiusSlider->setValue(40);
		ui.widthSlider->setValue(10);

		selectingFlag=false;
		selectingDraggingFlag=false;
	}

signals:
	void showStatusMessage(QString msg,int=0);
	
public slots:
	void on_actionDocumentContent_triggered(bool);
	void on_actionAbout_triggered(bool);
	void on_actionPaperConferenceAuthorGraph_triggered(bool);
	void on_actionTopicGraph_triggered(bool);
	void on_comboBoxTheme_activated(int index){
		setTheme(index+1);
		update();
	}
	void on_comboBox_activated(int index){
		setLayout(index+1);
		update();
	}
	void on_fontSizeSlider_valueChanged(int i){
		displayFontSize = i;
		if(whichGraphFlag)update();
	}
	void on_degreeSlider_valueChanged(int d){
		qDebug() << "slider!";
		displayMinDegree=d;
		
		if(whichGraphFlag==1){
			int n=tGraph.topics.size();
			for(int i=0; i<n; i++){
				tGraph.topics[i].filtered=(tGraph.topics[i].degree<displayMinDegree);
			}
		}else if(whichGraphFlag==2){
			for(Node* pN : pcaGraph.nodes){
				pN->filtered=pN->degree<displayMinDegree;
			}
		}
		if(whichGraphFlag)update();
	}
	void on_radiusSlider_valueChanged(int r){
		displayNodeRadius=(r/20.0);
		if(displayNodeRadius<1)
			displayNodeRadius=1;
		if(whichGraphFlag)update();
	}
	void on_widthSlider_valueChanged(int r){
		displayEdgeWidth=(r/20.0);
		if(whichGraphFlag)update();
	}
	
	void on_btnReset_clicked(){
		viewCenterX=0, viewCenterY=0; viewScale=1.0;
		update();
	}
	void on_btnRight_clicked(){
		moveX(10);
		update();
	}
	void on_btnLeft_clicked(){
		moveX(-10);
		update();
	}
	void on_btnUp_clicked(){
		moveY(-10);
		update();
	}
	void on_btnDown_clicked(){
		moveY(10);
		update();
	}
	void on_btnZoomIn_clicked(){
		zoomIn();
		update();
	}
	void on_btnZoomOut_clicked(){
		zoomOut();
		update();
	}
	
	void on_animationTimer(){
		doAnimationTimer();
	}

private:
	void paintEvent(QPaintEvent *ev);
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *e);
	void wheelEvent(QWheelEvent * e);
	void closeEvent(QCloseEvent *event);
	void doAnimationTimer(int callingAgain=0){
		animationPhase++;
		
		
		if(animationPhase>=nAnimationPhase){
			animationTimer->stop();
			return;
		}
		//qDebug() << "Timer Called" << animationPhase;
#define calcAnimationX(NODE) NODE.x += (NODE.animationX-NODE.x)/(nAnimationPhase-animationPhase);
#define calcAnimationY(NODE) NODE.y += (NODE.animationY-NODE.y)/(nAnimationPhase-animationPhase);
		if(whichGraphFlag==1){
			int n=tGraph.topics.size();
			for(int i=0; i<n; i++){
				calcAnimationX(tGraph.topics[i]);
				calcAnimationY(tGraph.topics[i]);
			}
		}else if(whichGraphFlag==2){
			//qDebug() << pcaGraph.papers[1].x;
			int n;
			n=pcaGraph.papers.size();
			for(int i=0; i<n; i++){
				calcAnimationX(pcaGraph.papers[i]);
				calcAnimationY(pcaGraph.papers[i]);
			}
			n=pcaGraph.authors.size();
			for(int i=0; i<n; i++){
				calcAnimationX(pcaGraph.authors[i]);
				calcAnimationY(pcaGraph.authors[i]);
			}
			n=pcaGraph.conferences.size();
			for(int i=0; i<n; i++){
				calcAnimationX(pcaGraph.conferences[i]);
				calcAnimationY(pcaGraph.conferences[i]);			
			}
		}

		update();

	}

	int adjustViewScale(double k_){//return 1 for failure
		int ret=0;
		double k = viewScale * k_;
		if(k<0.01) ret=1, k=0.01;
		if(k>100)  ret=1, k=100;
		viewScale = k;
		showStatusMessage("Zoom "+QString::number(viewScale)+"x.",1000);
		return ret;
	}
	void moveX(int x=0){
		qDebug() << "moving x   " << x;
		viewCenterX+=x;
	}
	void moveY(int y=0){
		qDebug() << "moving y   " << y;
		viewCenterY+=y;
	}
	void setLayout(int layout){
		if(whichLayoutFlag==layout)
			return;
		bool dontCallTimer = true;
		if(whichLayoutFlag==-1)

		whichLayoutFlag = layout;
		
		if(whichGraphFlag==1){
			int n=tGraph.topics.size();
			if(layout==1){
				for(int i=0; i<n; i++){
					tGraph.topics[i].animationX=tGraph.topics[i].FMMMx;
					tGraph.topics[i].animationY=tGraph.topics[i].FMMMy;
				}
			}else if(layout==3){
				for(int i=0; i<n; i++){
					tGraph.topics[i].animationX=tGraph.topics[i].CircularX;
					tGraph.topics[i].animationY=tGraph.topics[i].CircularY;
				}
			}else if(layout==2){
				for(int i=0; i<n; i++){
					tGraph.topics[i].animationX=tGraph.topics[i].GridX;
					tGraph.topics[i].animationY=tGraph.topics[i].GridY;
				}
			}else if(layout==4){
				for(int i=0; i<n; i++){
					tGraph.topics[i].animationX=tGraph.topics[i].CCircularX;
					tGraph.topics[i].animationY=tGraph.topics[i].CCircularY;
				}
			}else if(layout==5){
				for(int i=0; i<n; i++){
					tGraph.topics[i].animationX=tGraph.topics[i].LZYx;
					tGraph.topics[i].animationY=tGraph.topics[i].LZYy;
				}
			}else{
				//TODO
			}
		}else if(whichGraphFlag==2){
			if(layout==1){
				for(Node* pN : pcaGraph.nodes){
					pN->animationX=pN->FMMMx;
					pN->animationY=pN->FMMMy;
				}
			}else if(layout==3){
				for(Node* pN : pcaGraph.nodes){
					pN->animationX=pN->CircularX;
					pN->animationY=pN->CircularY;
				}
			}else if(layout==2){
				for(Node* pN : pcaGraph.nodes){
					pN->animationX=pN->GridX;
					pN->animationY=pN->GridY;
				}
			}else if(layout==4){
				for(Node* pN : pcaGraph.nodes){
					pN->animationX=pN->CCircularX;
					pN->animationY=pN->CCircularY;
				}
			}else if(layout==5){
				for(Node* pN : pcaGraph.nodes){
					pN->animationX=pN->LZYx;
					pN->animationY=pN->LZYy;
				}
			}else{
				//TODO
			}
		}
		//if(!dontCallTimer)
		{
			animationPhase=0;
			animationTimer->start();
		}

	}
	void zoomIn(){
		qDebug() << "zooming in ";
		adjustViewScale(1.1);
	}
	void zoomOut(){
		qDebug() << "zooming out";
		adjustViewScale(0.9);
	}
	void checkFile(std::string fileName){
		ifstream input(fileName);
		if(!input.is_open()){
			QMessageBox msgBox;
			msgBox.setText(QString("Cannot find file '")+QString::fromStdString(fileName)+"'.\n\nPlease check and restart this program.");
			msgBox.exec();
			exit(0);
		}	
	}
private:
	Ui::GraphVisualizerClass ui;
};

#endif // GRAPHVISUALIZER_H
