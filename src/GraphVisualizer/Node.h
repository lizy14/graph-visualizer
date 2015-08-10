#ifndef NODE_H
#define NODE_H


class Node;
class TopicNode;
class PaperNode;
class ConferenceNode;
class AuthorNode;

#define NORMALIZED_GRAPH_WIDTH_AND_HEIGHT 500
#define NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF 250
#define NORMALIZED_GRAPH_LEFT 30
#define NORMALIZED_GRAPH_TOP 60

#include <string>

#include "Edge.h"
#include <ogdf/basic/Graph.h>
using std::string;


class Node{
public:
	int id;
	int degree;
	bool filtered;
	bool highlighted;
	ogdf::node ogdfID;
	double FMMMx,FMMMy;
	double SugiyamaLayoutX,SugiyamaLayoutY;
	double CircularX,CircularY;
	double CCircularX,CCircularY;
	int	GridX,GridY;
	double LZYx, LZYy;
	double x, y; //用于绘图的坐标
	double animationX, animationY;//动画目的地坐标
	Node()
		:degree(0),filtered(false),highlighted(false),
		x(NORMALIZED_GRAPH_LEFT+NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF),
		y(NORMALIZED_GRAPH_TOP +NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF)
	{}
};
class TopicNode : public Node{
public:
	string topicWords;
	string topicDocuments;
};
class PaperConferenceAuthorNode :public Node{
public:
	string type_;
	string year;
	string strID;

	string name;
	string nameShort;

	string viewColor;
	string viewLabel;
	string viewLayout;
	double viewLayoutX,viewLayoutY;
};
class PaperNode :public PaperConferenceAuthorNode{
public:
	string authors;
	string dateFrom;
	string pageFrom;
};
class AuthorNode :public PaperConferenceAuthorNode{

};
class ConferenceNode :public PaperConferenceAuthorNode{

};


#endif