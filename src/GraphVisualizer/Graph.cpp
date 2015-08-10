/*
文件名: 
描　述: 

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-07-25

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include "Graph.h"
#include "graphvisualizer.h"

#include <cmath>
#include <cstdio>
#include <fstream>
#include <ogdf/basic/GridLayout.h>
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/fileformats/GraphIO.h>
#include <ogdf/layered/MedianHeuristic.h>
#include <ogdf/layered/OptimalHierarchyLayout.h>
#include <ogdf/layered/OptimalRanking.h>
#include <ogdf/layered/SugiyamaLayout.h>
#include <string>
using namespace ogdf;
using namespace std;



//for LZY layout
struct LzyPoint{
	double x, y;
};
LzyPoint fLzyPoint(double i){
	double l=i*3.436;
	LzyPoint p;
	if(l<.7){
		p.x=0;
		p.y=l;
		return p;
	}
	l-=.7;
	if(l<.3){
		p.y=0;
		p.x=l;
		return p;
	}
	l-=.3;
	if(l<.4){
		p.y=1;
		p.x=.3+l-.05;
		return p;
	}
	l-=.4;
	if(l<.566){
		p.x=.7-l*.4/.566-.05;
		p.y=1.0-l*.4/.566;
		return p;
	}
	l-=.566;
	if(l<.4){
		p.x=0.3+l-.05;
		p.y=.6;
		return p;
	}
	l-=.4;
	if(l<.335){
		p.x=.7+l*.15/.335;
		p.y=.7-l*.3/.335;
		return p;
	}
	l-=.335;
	if(l<.335){
		p.x=1.0-l*.15/.335;
		p.y=.7-l*.3/.335;
		return p;
	}
	l-=.335;
	p.x=.85;
	p.y=.4-l;
	return p;
}

int TopicGraph::calcDegree(){
	for(UndirectedEdge i:edges){
		i.nodeA->degree++, i.nodeB->degree++;
	}
	int max_=0;
	for(TopicNode i:topics){
		if(i.degree>max_)max_=i.degree;
	}
	return max_;
}
int PaperConferenceAuthorGraph::calcDegree(){
	for(DirectedEdge i:edges){
		i.nodeA->degree++, i.nodeB->degree++;
	}
	int max_=0;
	for(Node* pN:nodes){
		if(pN->degree>max_)max_=pN->degree;
	}
	return max_;
}

void TopicGraph::doLayout(){
	qDebug() <<  QTime::currentTime();
	Graph G;
	int n=topics.size();

	for(int i=0; i<n;i++){
		topics[i].ogdfID = G.newNode(i);
	}
	for(UndirectedEdge i : edges){
		G.newEdge(i.nodeA->ogdfID,i.nodeB->ogdfID);
	}




	//FMMM
	GraphAttributes GA_FMMM(G);
	FMMMLayout Layout;
	Layout.useHighLevelOptions(true);
	Layout.unitEdgeLength(15.0);
	Layout.newInitialPlacement(true);
	Layout.qualityVersusSpeed(FMMMLayout::qvsGorgeousAndEfficient);
	Layout.call(GA_FMMM);

	DRect rect=GA_FMMM.boundingBox();

	double xk=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/rect.width();
	double yk=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/rect.height();
	double x0=rect.p1().m_x; //最小x
	double y0=rect.p1().m_y; //最小y

	for(int i=0; i<topics.size();i++){
		//坐标转化到 [0,NORMALIZED_GRAPH_WIDTH_AND_HEIGHT] 区间内
		topics[i].FMMMx = (GA_FMMM.x(topics[i].ogdfID)-x0)*xk+NORMALIZED_GRAPH_LEFT;
		topics[i].FMMMy = (GA_FMMM.y(topics[i].ogdfID)-y0)*yk+NORMALIZED_GRAPH_TOP;
	}
	qDebug() <<  QTime::currentTime();
	double delta = 2*3.1415927 / n;
	int sqrt_ = ceil(sqrt(n));
	for(int i=0; i<n;i++){
		topics[i].CircularX = NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+sin(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_LEFT;;
		topics[i].CircularY = NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+cos(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_TOP;
		topics[i].GridX =  NORMALIZED_GRAPH_LEFT+(NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/sqrt_)*(i / sqrt_);
		topics[i].GridY =  NORMALIZED_GRAPH_TOP+(NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/sqrt_)*(i % sqrt_);
		topics[i].CCircularX=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+(i%2?1:0.7)*sin(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_LEFT;
		topics[i].CCircularY=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+(i%2?1:0.7)*cos(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_TOP;
		LzyPoint lzyPoint=fLzyPoint(i/(double)n);
		lzyPoint.y = 1-lzyPoint.y;
		topics[i].LZYx= NORMALIZED_GRAPH_LEFT+NORMALIZED_GRAPH_WIDTH_AND_HEIGHT*lzyPoint.x;	
		topics[i].LZYy= NORMALIZED_GRAPH_TOP +NORMALIZED_GRAPH_WIDTH_AND_HEIGHT*lzyPoint.y;
	}
	qDebug() <<  QTime::currentTime();
	return;
}
void PaperConferenceAuthorGraph::doLayout(){
	Graph G;
	for(Node* pN : nodes){
		pN->ogdfID=G.newNode(pN->id);
	}

	for(DirectedEdge i : edges){
		G.newEdge(i.nodeA->ogdfID,i.nodeB->ogdfID);
	}

	//FMMM
	GraphAttributes GA_FMMM(G);
	FMMMLayout Layout;
	Layout.useHighLevelOptions(true);
	Layout.unitEdgeLength(15.0);
	Layout.newInitialPlacement(true);
	Layout.qualityVersusSpeed(FMMMLayout::qvsGorgeousAndEfficient);
	Layout.call(GA_FMMM);

	DRect rect=GA_FMMM.boundingBox();
	double xk=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/rect.width();
	double yk=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/rect.height();
	double x0=rect.p1().m_x; //最小x
	double y0=rect.p1().m_y; //最小y

#define fx(x_)  ((x_)-x0)*xk+NORMALIZED_GRAPH_LEFT;
#define fy(y_)  ((y_)-y0)*yk+NORMALIZED_GRAPH_TOP;
	for(Node* pN: nodes){
		pN->FMMMx = fx(GA_FMMM.x(pN->ogdfID));
		pN->FMMMy = fy(GA_FMMM.y(pN->ogdfID));
	}

	//Circular
	int n=nodes.size();
	double delta = 2*3.1415927 / n;
	int sqrt_ = ceil(sqrt(n));

	int i=0;
	for(Node* pN: nodes){
		pN->CircularX = NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+sin(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_LEFT;
		pN->CircularY = NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+cos(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_TOP;
		pN->GridX = NORMALIZED_GRAPH_LEFT+(NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/sqrt_)*(i / sqrt_);
		pN->GridY = NORMALIZED_GRAPH_TOP+(NORMALIZED_GRAPH_WIDTH_AND_HEIGHT/sqrt_)*(i % sqrt_);
		pN->CCircularX=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+(i%2?1:0.7)*sin(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_LEFT;
		pN->CCircularY=NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+(i%2?1:0.7)*cos(delta * i)*NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF+NORMALIZED_GRAPH_TOP;
		LzyPoint lzyPoint=fLzyPoint(1.0-i/(double)n);
		lzyPoint.y = 1-lzyPoint.y;
		pN->LZYx= NORMALIZED_GRAPH_LEFT+NORMALIZED_GRAPH_WIDTH_AND_HEIGHT*lzyPoint.x;	
		pN->LZYy= NORMALIZED_GRAPH_TOP +NORMALIZED_GRAPH_WIDTH_AND_HEIGHT*lzyPoint.y;
		i++;
	}

	return;


}

void TopicGraph::bind(){
	int n=edges.size();
	for(int i=0; i<n; i++){
		edges[i].nodeA=getNode(edges[i].idA);
		edges[i].nodeB=getNode(edges[i].idB);
	}
}
void PaperConferenceAuthorGraph::bind(){
	int n=edges.size();
	for(int i=0; i<n; i++){
		edges[i].nodeA=getNode(edges[i].idA);
		edges[i].nodeB=getNode(edges[i].idB);
	}
}

void TopicGraph::importNodesFromTXT(string fileName){
	topics.clear();
	ifstream file(fileName);

	while(!file.eof()){
		TopicNode node;
		file >> node.id;
		getline(file,string());
		getline(file,node.topicWords);
		getline(file,node.topicDocuments);
		if(!file.good()) break;
		topics.push_back(node);
	}
}
void TopicGraph::importEdgesFromTXT(string fileName){
	edges.clear();
	ifstream file(fileName);

	while(!file.eof()){
		UndirectedEdge edge;
		int _1, _2; double _3;
		file >> _1 >> _2 >> _3;
		if(!file.good()) break;
		edge.setEdge(_1, _2, _3);
		edges.push_back(edge);
	}
}
void PaperConferenceAuthorGraph::importNodesFromTXT(string fileName){
	papers.clear();
	conferences.clear();
	authors.clear();
	ifstream file(fileName);

	while(!file.eof()){
		int id_; string type__;
		file >> id_;
		getline(file,string());
		getline(file, type__);
		if(!file.good()) break;
		if(type__.find("paper")!=std::string::npos){
			PaperNode node;
			node.id=id_;
			node.type_=type__;
			getline(file, node.year);
			getline(file, node.authors);
			getline(file, node.dateFrom);
			getline(file, node.strID);
			getline(file, node.pageFrom);
			getline(file, node.name);
			getline(file, node.nameShort);
			getline(file, node.viewColor);
			getline(file, node.viewLabel);
			getline(file, node.viewLayout);
			papers.push_back(node);
		}else if(type__.find("author")!=std::string::npos){
			AuthorNode node;
			node.id=id_;
			node.type_=type__;
			getline(file, node.year);
			getline(file, node.strID);

			getline(file, node.name);
			getline(file, node.nameShort);
			getline(file, node.viewColor);
			getline(file, node.viewLabel);
			getline(file, node.viewLayout);
			authors.push_back(node);
		}else if(type__.find("conference")!=std::string::npos){
			ConferenceNode node;
			node.id=id_;
			node.type_=type__;
			getline(file, node.year);
			getline(file, node.strID);
			getline(file, node.name);
			getline(file, node.nameShort);
			getline(file, node.viewColor);
			getline(file, node.viewLabel);
			getline(file, node.viewLayout);
			conferences.push_back(node);
		}
		if(!file.good()) break;
	}
}
void PaperConferenceAuthorGraph::importEdgesFromTXT(string fileName){
	edges.clear();
	ifstream file(fileName);

	while(!file.eof()){
		DirectedEdge edge;
		int _1, _2;
		file >> _1 >> _2;
		if(!file.good()) break;
		edge.setEdge(_1, _2);
		edges.push_back(edge);
	}
}
