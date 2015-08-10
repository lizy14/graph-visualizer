/*
文件名: 
描　述: 

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#include "graphvisualizer.h"


#include "Graph.h"
#include <cmath>
#include <ogdf/energybased/FMMMLayout.h>
#include <QTransform>
using namespace ogdf;

void GraphVisualizer::paintEvent(QPaintEvent *ev){
	//qDebug() << "paintStart" << QTime::currentTime();

	bool thereIsAnyMouseOver=false;
	if(whichGraphFlag==0){

	}
	if(whichGraphFlag==1){
		
		QPainter p(this);
		QPen pen;
		QPalette palette(this->palette());
		p.setBrush(palette.windowText());
		p.setPen(pen);
		
		QFont font;

		//draw edges
		int fontSize_=transformR(displayFontSize)/4;
		if(fontSize_<1)fontSize_=1;
		font.setPointSize(fontSize_);p.setFont(font);
		
		pen.setWidth(transformR(displayEdgeWidth));
		pen.setColor(COLOR_EDGE_NORMAL);
		p.setPen(pen);
		for(UndirectedEdge i: tGraph.edges){
			bool filtered=(i.nodeA->degree<displayMinDegree
				|| i.nodeB->degree<displayMinDegree);
			bool highlighted=i.nodeA->highlighted && i.nodeB->highlighted;
			if(filtered){pen.setColor(COLOR_EDGE_FILTERED);p.setPen(pen);}
			if(highlighted){pen.setColor(COLOR_EDGE_HIGHLIGHTED);p.setPen(pen);}
			if(highlighted){
				
				QString strWeight=QString::number(i.weight,'f',3).mid(1);
				//handle rotation
				double k=
					(transformY(i.nodeA->y)-transformY(i.nodeB->y))/
					(transformX(i.nodeA->x)-transformX(i.nodeB->x)+0.0);
				double textX=(transformX(i.nodeA->x)+transformX(i.nodeB->x))/2.0;
				double textY=(transformY(i.nodeA->y)+transformY(i.nodeB->y))/2.0;
				
				double alpha=std::atan(k) ;
				
				QPointF textPoint(textX, textY);
				QTransform transform;
				transform.rotateRadians(alpha);
				p.setTransform(transform);

				QPointF drawTextPoint=transform.inverted().map(textPoint);
				drawTextPoint.setY(drawTextPoint.y()-transformR(displayEdgeWidth));
				drawTextPoint.setX(drawTextPoint.x()-p.fontMetrics().width(strWeight)/2.0);

				p.drawText(
					drawTextPoint,
					strWeight
					);
				transform.rotateRadians(-alpha);
				p.setTransform(transform);
			}
			p.drawLine(
				transformX(i.nodeA->x),
				transformY(i.nodeA->y),
				transformX(i.nodeB->x),
				transformY(i.nodeB->y)
				);
			if(filtered||highlighted){pen.setColor(COLOR_EDGE_NORMAL);p.setPen(pen);}
		}
	
		
		//draw nodes
		fontSize_=transformR(displayFontSize)/2;
		if(fontSize_<1)fontSize_=1;
		font.setPointSize(fontSize_);p.setFont(font);
		pen.setWidth(1);
		pen.setColor(COLOR_NODE_EDGE_NORMAL);
		p.setPen(pen);
		p.setBrush(COLOR_NODE_NORMAL);
		for(TopicNode i: tGraph.topics){
			int x,y;double r=transformR(2);
			x=transformX(i.x), y=transformY(i.y);
			
			bool mouseOver=mouseX && mouseY && (mouseOverNodeIndex!=-1 && i.id==tGraph.topics[mouseOverNodeIndex].id);
			bool clicked=clickedNodeIndex!=-1 && i.id==tGraph.topics[clickedNodeIndex].id;
			bool dragging=draggingNodeIndex!=-1 && i.id==tGraph.topics[draggingNodeIndex].id;
			bool highlighted=i.highlighted || selectedNodeIDs.count(i.id);
			bool light=i.filtered;
			
			if(mouseOver||highlighted){
				QPen oldpen=p.pen();
				p.setPen(QPalette(this->palette()).windowText().color());
				p.drawText(x+r+2, y, QString::number(i.id));
				p.setPen(oldpen);
			}
			
			if(mouseOver){
				thereIsAnyMouseOver=true;
				this->setCursor(Qt::PointingHandCursor);
			}
			if(light)p.setPen(COLOR_NODE_EDGE_FILTERED);

			if(light)p.setBrush(COLOR_NODE_FILTERED);
			if(highlighted)p.setBrush(COLOR_NODE_HIGHLIGHTED);
			if(clicked)p.setBrush(COLOR_NODE_CLICKED);
			if(mouseOver)p.setBrush(COLOR_NODE_MOUSEOVER);
			if(dragging)p.setBrush(COLOR_NODE_DRAGGING);

			r *= displayNodeRadius;//(mouse?displayNodeRadius:displayNodeRadius-1);

			if(mouseOver) r*=1.5;
			p.drawEllipse(QPoint(x, y), (int)r, (int)r);

			//restore
			if(light||mouseOver||clicked||dragging||highlighted)p.setBrush(COLOR_NODE_NORMAL);
			if(light)p.setPen(COLOR_NODE_EDGE_NORMAL);
		}
		if(!thereIsAnyMouseOver)this->setCursor(Qt::ArrowCursor);

	}else if((whichGraphFlag==2)){
		QPainter p(this);
		QPen pen;
		p.setPen(pen);

		QFont font;
		
		//draw edges
		int fontSize_=transformR(displayFontSize)/2;
		if(fontSize_<1)fontSize_=1;
		font.setPointSize(fontSize_);p.setFont(font);
		pen.setWidth(transformR(displayEdgeWidth));
		pen.setColor(COLOR_EDGE_NORMAL);
		p.setPen(pen);
		for(DirectedEdge i: pcaGraph.edges){
			bool filtered=(i.nodeA->degree<displayMinDegree
				|| i.nodeB->degree<displayMinDegree);
			bool highlighted=i.nodeA->highlighted && i.nodeB->highlighted;
			if(filtered){pen.setColor(COLOR_EDGE_FILTERED);p.setPen(pen);}
			if(highlighted){pen.setColor(COLOR_EDGE_HIGHLIGHTED);p.setPen(pen);}
			p.drawLine(
				transformX(i.nodeA->x),
				transformY(i.nodeA->y),
				transformX(i.nodeB->x),
				transformY(i.nodeB->y)
				);
			if(filtered||highlighted){pen.setColor(COLOR_EDGE_NORMAL);p.setPen(pen);}
		}

		//draw nodes
		pen.setWidth(1);
		pen.setColor(COLOR_NODE_EDGE_NORMAL);
		p.setPen(pen);
				
		for(Node* pN:pcaGraph.nodes){
			Node i=*pN;
			PaperConferenceAuthorNode *pPCAN = (PaperConferenceAuthorNode *)pN;
			int x,y;double r=transformR(2);
			x=transformX(i.x), y=transformY(i.y);
			if(pPCAN->type_=="type: paper")
				p.setBrush(COLOR_NODE_PAPER);
			else if(pPCAN->type_=="type: author")
				p.setBrush(COLOR_NODE_AUTHOR);
			else if(pPCAN->type_=="type: conference")
				p.setBrush(COLOR_NODE_CONFERENCE);

			bool mouseOver= mouseX && mouseY && mouseOverNodeIndex==i.id;
			bool clicked=clickedNodeIndex!=-1 && i.id==clickedNodeIndex;
			bool dragging= (draggingNodeIndex!=-1 && i.id==draggingNodeIndex);
			bool highlighted=i.highlighted || selectedNodeIDs.count(i.id);
			bool light=i.filtered;

			if(mouseOver||highlighted){
				QPen oldpen=p.pen();
				p.setPen(QPalette(this->palette()).windowText().color());
				p.drawText(x+r+2, y, QString::number(i.id));
				p.setPen(oldpen);
			}
			
			if(mouseOver){
				thereIsAnyMouseOver=true;
				this->setCursor(Qt::PointingHandCursor);
			}

			if(light)p.setPen(COLOR_NODE_EDGE_FILTERED);

			if(light)p.setBrush(COLOR_NODE_FILTERED);
			if(highlighted)p.setBrush(COLOR_NODE_HIGHLIGHTED);
			if(clicked)p.setBrush(COLOR_NODE_CLICKED);
			if(mouseOver)p.setBrush(COLOR_NODE_MOUSEOVER);
			if(dragging)p.setBrush(COLOR_NODE_DRAGGING);

			r *= displayNodeRadius;//(mouse?displayNodeRadius:displayNodeRadius-1);
			
			if(mouseOver) r*=1.5;
			p.drawEllipse(QPoint(x, y), (int)r, (int)r);


			//restore
			if(light||mouseOver||clicked||dragging||highlighted)p.setBrush(COLOR_NODE_PAPER);
			if(light)p.setPen(COLOR_NODE_EDGE_NORMAL);
		}
		if(!thereIsAnyMouseOver)this->setCursor(Qt::ArrowCursor);

	}

	//draw multi-selection box
	if(selectingFlag && !selectingDraggingFlag){
		QPainter p(this);
		
		p.setBrush(COLOR_SELECT_BOX.lighter());
		p.setPen(Qt::PenStyle::NoPen);
		p.drawRect(selectedRect());
	}

	//qDebug() << "paintEnd  " <<QTime::currentTime();
}
void GraphVisualizer::on_actionDocumentContent_triggered(bool){
	viewer.setFileName(FILENAME_TGDC);
	viewer.show();
}
void GraphVisualizer::on_actionAbout_triggered(bool){
	QMessageBox msgbox;
	msgbox.setText("Graph Visualizer<br/>By Zhaoyang Li, THSS.<br/>2015.8.<br /><br/>Uses Qt 5.3, OGDF v2015.05.");
	msgbox.setWindowTitle("About");
	msgbox.exec();
}
void GraphVisualizer::on_actionTopicGraph_triggered(bool){
	init();

	

	emit showStatusMessage("Loading TopicGraph from file...");
	tGraph.importNodesFromTXT(FILENAME_TGN);
	tGraph.importEdgesFromTXT(FILENAME_TGE);	
	tGraph.bind();
	 
	ui.degreeSlider->setMaximum(tGraph.calcDegree()+1);



	emit showStatusMessage("Executing layout...");
	tGraph.doLayout();



	whichGraphFlag=1;
	setLayout(1);



	emit showStatusMessage("TopicGraph Loaded. Displayed in force-directed layout.", 5000);
	

	ui.comboBox->clear();
	ui.comboBox->addItem("Force directed");
	ui.comboBox->addItem("Grid");
	ui.comboBox->addItem("Circular");
	ui.comboBox->addItem("Circular x2");
	ui.comboBox->addItem("LZY");
	
	update();

}
void GraphVisualizer::on_actionPaperConferenceAuthorGraph_triggered(bool){
	init();


	
	
	emit showStatusMessage("Loading TopicGraph from file...");
	pcaGraph.importNodesFromTXT(FILENAME_PCAN);
	pcaGraph.importEdgesFromTXT(FILENAME_PCAE);	
	
	pcaGraph.makeUnionNodeVector();
	pcaGraph.bind();

	ui.degreeSlider->setMaximum(pcaGraph.calcDegree()+1);



	emit showStatusMessage("Executing layout...");
	pcaGraph.doLayout();



	whichGraphFlag=2;
	setLayout(1);



	emit showStatusMessage("PaperConferenceAuthorGraph Loaded. Displayed in force-directed layout.", 5000);


	ui.comboBox->clear();
	ui.comboBox->addItem("Force directed");
	ui.comboBox->addItem("Grid");
	ui.comboBox->addItem("Circular");
	ui.comboBox->addItem("Circular x2");
	ui.comboBox->addItem("LZY");
	
	update();

}

GraphVisualizer::GraphVisualizer(QWidget *parent)
	:
	QMainWindow(parent)


{
	checkFile(FILENAME_PCAE);
	checkFile(FILENAME_PCAN);
	checkFile(FILENAME_TGE);
	checkFile(FILENAME_TGN);
	checkFile(FILENAME_TGDC);


	animationTimer = new QTimer(this);
	animationTimer->setInterval(20);
	connect(animationTimer, SIGNAL(timeout()),this, SLOT(on_animationTimer()));

	
	ui.setupUi(this);
	ui.comboBoxTheme->clear();
	ui.comboBoxTheme->addItem("Daytime");
	ui.comboBoxTheme->addItem("Nighttime");
	ui.comboBoxTheme->addItem("Tsinghua Purple");
	ui.comboBoxTheme->addItem("Random A");
	ui.comboBoxTheme->addItem("Random B");
	setTheme(1);

	init();
	
	connect (this, SIGNAL(showStatusMessage(QString,int)), ui.statusBar, SLOT(showMessage(QString,int)));
	showStatusMessage("Welcome to Graph Visualizer.",5000);
	
	//init done.
	//on_actionTopicGraph_triggered(0);
	//on_actionPaperConferenceAuthorGraph_triggered(0);
	return;
}
GraphVisualizer::~GraphVisualizer()
{
}
void GraphVisualizer::closeEvent(QCloseEvent *event){
	viewer.close();
	QMainWindow::closeEvent(event);
}
void GraphVisualizer::mousePressEvent(QMouseEvent * ev){
	mouseDownFlag=1;
	if(ev->button()==Qt::RightButton){
		qDebug() << "right button down!";
		
		selectStartX=ev->x(), selectStartY=ev->y();
		if(selectedNodes.size()){
			selectingDraggingFlag=true;
			selectingFlag=false;
		}
	}else{
		clickedNodeIndex=draggingNodeIndex=mouseOverNodeIndex;
	}
	
	
	update();
	
}
void GraphVisualizer::mouseReleaseEvent(QMouseEvent *ev){
	if(whichGraphFlag==1){
		int n=tGraph.topics.size();

		if(!draggingFlag){
			for(int i=0; i<n; i++){
				tGraph.topics[i].highlighted=false;
			}
			if(clickedNodeIndex==-1)ui.textEdit->clear();
		}

		if(clickedNodeIndex!=-1){
			for(int i=0; i<n; i++){
				if(tGraph.isConnected(clickedNodeIndex, i))
					tGraph.topics[i].highlighted=true;
			}
		}
	}else if(whichGraphFlag==2){
		if(!draggingFlag){
			for(Node* pN:pcaGraph.nodes){
				pN->highlighted=false;
			}
			if(clickedNodeIndex==-1)ui.textEdit->clear();
		}

		if(clickedNodeIndex!=-1){
			for(Node* pN: pcaGraph.nodes){
				if(pcaGraph.isConnected(clickedNodeIndex,pN->id))
					pN->highlighted=true;
			}
			pcaGraph.getNode(clickedNodeIndex)->highlighted=true;
		}
	}
	if(!draggingFlag){
		selectedNodes.clear();
		selectedNodeIDs.clear();
		selectingFlag=false;
		selectingDraggingFlag=false;
	}
	mouseDownFlag=0;
	draggingFlag=false;
	draggingNodeIndex=-1;
	if(selectingFlag && selectedNodes.size())
		emit showStatusMessage("Use your right mouse button to drag selected nodes. Left-click to quit multi-selection mode.", 5000);
	else
		emit showStatusMessage("");
	selectingFlag=false;

	update();
}
void GraphVisualizer::mouseMoveEvent(QMouseEvent *e){  
	if(mouseDownFlag){
		clickedNodeIndex=-1;
		draggingFlag=true;
	}
	int x=e->x();
	int y=e->y();
	if(e->buttons() & Qt::RightButton){
		if(mouseDownFlag){
			if(!selectingFlag)
				emit showStatusMessage("Multi-selection mode.", 5000);
			selectingFlag=true;
			
		}
		//qDebug() << "moving with right button down!";
		
		if(selectedNodes.size() && selectingDraggingFlag){
			for(Node* i : selectedNodes){
				i->x -= (mouseX-x)/viewScale;
				i->y -= (mouseY-y)/viewScale;
			}
			mouseX = x, mouseY = y;
		}else{
			mouseX = x, mouseY = y;
			QRect selectedRect_ = selectedRect();
			selectedNodes.clear();
			selectedNodeIDs.clear();
			if(whichGraphFlag==1){
				int n=tGraph.topics.size();
				for(int i=0; i<n; i++){
					if(selectedRect_.contains(QPoint(transformX(tGraph.topics[i].x),transformY(tGraph.topics[i].y)))){
						selectedNodes.insert(&tGraph.topics[i]);
						selectedNodeIDs.insert(tGraph.topics[i].id);
					}
				}
			}else if(whichGraphFlag==2){
				for(Node* pN:pcaGraph.nodes){
					if(selectedRect_.contains(QPoint(transformX(pN->x),transformY(pN->y)))){
						selectedNodes.insert(pN);
						selectedNodeIDs.insert(pN->id);
					}
				}
			}
		}
		update();
	}else
	if(draggingNodeIndex!=-1){
		if(whichGraphFlag==1){
			tGraph.topics[draggingNodeIndex].x -= (mouseX-x)/viewScale;
			tGraph.topics[draggingNodeIndex].y -= (mouseY-y)/viewScale;
		}else if(whichGraphFlag==2){
			Node* pN=pcaGraph.getNode(draggingNodeIndex);
			pN->x  -= (mouseX-x)/viewScale;
			pN->y  -= (mouseY-y)/viewScale;
		}
	}else if(mouseDownFlag){
		viewCenterX -= (mouseX-x)/viewScale;
		viewCenterY -= (mouseY-y)/viewScale;
	}else{//mouse over
		mouseOverNodeIndex=-1;
		int minDistance = -1;
		if(whichGraphFlag==1){
			int n=tGraph.topics.size();
			for(int i=0; i<n; i++){
				int x_,y_;double r=transformR(2);
				x_=transformX(tGraph.topics[i].x);
				y_=transformY(tGraph.topics[i].y);
				
				bool mouseOver = (f(x, x_, displayNodeRadius*r) && f(y, y_, displayNodeRadius*r));
				
				if(mouseOver){
					int distance=(x-x_)*(x-x_)+(y-y_)*(y-y_);
					if((distance<minDistance || minDistance==-1)&&mouseOverNodeIndex!=i){
						mouseOverNodeIndex=i;
						minDistance=distance;
							QString neighbours;
							
							for(int j=0; j<n;j++){
								if(i==j)continue;
								double w=tGraph.isConnected(i, j);
								if(w)
									neighbours += "#"+QString::number(tGraph.topics[j].id)+"("+QString::number(w)+"), ";
							}
								
							ui.textEdit->setText("<b><i>Node</i></b> #"+QString::number(tGraph.topics[i].id)
								+"<br><b>neighbours</b>:<br>"+neighbours+"<br>degree="+QString::number(tGraph.topics[i].degree)+"."
								+"<br><b>topic words</b>:<br>"+QString::fromStdString(tGraph.topics[i].topicWords.substr(11))
								+"<br><b>topic documents</b>:<br>"+QString::fromStdString(tGraph.topics[i].topicDocuments.substr(15)));
					}
				}
			}
		}else if(whichGraphFlag==2){
			for(Node* pN:pcaGraph.nodes){
				PaperConferenceAuthorNode *pPCAN=(PaperConferenceAuthorNode*)pN;

				int x_,y_;double r=transformR(2);
				x_=transformX(pN->x), y_=transformY(pN->y);
				bool mouseOver = (f(x, x_, displayNodeRadius*r) && f(y, y_, displayNodeRadius*r));
				if(mouseOver){
					int distance=(x-x_)*(x-x_)+(y-y_)*(y-y_);
					if((distance<minDistance || minDistance==-1)&&mouseOverNodeIndex!=pN->id){
						mouseOverNodeIndex=pN->id;
						minDistance=distance;
						
						if(pPCAN->type_=="type: paper"){
							PaperNode i = *(PaperNode*)pPCAN;
							ui.textEdit->setText("<b><i>Paper</i></b> #"+QString::number(i.id)+", degree="+QString::number(i.degree)+"<br><b>name</b>:<br>"+QString::fromStdString(i.name.substr(11))
								+"<br><b>short name</b>:<br>"+QString::fromStdString(i.nameShort.substr(16))
								+"<br><b>authors</b>:<br>"+QString::fromStdString(i.authors.substr(8)).replace(QString("\\n"),QString("<br>"))
								+"<br><b>date from</b>:<br>"+QString::fromStdString(i.dateFrom.substr(9))
								+"<br><b>page from</b>:<br>"+QString::fromStdString(i.pageFrom.substr(9))
								+"<br><b>id</b>:<br>"+QString::fromStdString(i.strID.substr(6))
								);
						}else if(pPCAN->type_=="type: author"){
							AuthorNode i = *(AuthorNode*)pPCAN;
							ui.textEdit->setText("<b><i>Author</i></b> #"+QString::number(i.id)+", degree="+QString::number(i.degree)+"<br><b>name</b>:<br>"+QString::fromStdString(i.name.substr(11))
								+"<br><b>short name</b>:<br>"+QString::fromStdString(i.nameShort.substr(16))
								+"<br><b>year</b>:<br>"+QString::fromStdString(i.year.substr(5))
								+"<br><b>id</b>:<br>"+QString::fromStdString(i.strID.substr(3)));
						}else if(pPCAN->type_=="type: conference"){
							ConferenceNode i = *(ConferenceNode*)pPCAN;
							ui.textEdit->setText("<b><i>Conference</i></b> #"+QString::number(i.id)+", degree="+QString::number(i.degree)+"<br><b>name</b>:<br>"+QString::fromStdString(i.name.substr(15))
								+"<br><b>short name</b>:<br>"+QString::fromStdString(i.nameShort.substr(20))
								+"<br><b>year</b>:<br>"+QString::fromStdString(i.year.substr(5))
								+"<br><b>id</b>:<br>"+QString::fromStdString(i.strID.substr(3)));
						}
					}	
				}
			}
		}
	}
	mouseX=x;
	mouseY=y;
	//qDebug() << "mouse: "		 << mouseX <<", "<< mouseY;
	update();
}  
void GraphVisualizer::wheelEvent(QWheelEvent * e){
	
	qDebug() << "wheel " << e->delta();
	int n = e->delta()/60;
	double k=1.0;

	if(n>0){
		for(int j=0;j<n;j++)
			k*=1.1;
	}else{
		for(int j=0;j>n;j--)
			k*=0.9;
	}
	if(adjustViewScale(k)) return;
	viewCenterX += (1-k)*mouseX/viewScale;
	viewCenterY += (1-k)*mouseY/viewScale;

	update();
}
 