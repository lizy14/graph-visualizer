#ifndef EDGE_H
#define EDGE_H

class DirectedEdge;
class UndirectedEdge;
#include "Node.h"


class Edge{
public:
	int idA, idB;
	double weight;
	virtual void setEdge(int, int, double=0)=0;
};
class UndirectedEdge : public Edge{
public:
	UndirectedEdge(){}
	UndirectedEdge(int idA_, int idB_, double weight_=0){
		setEdge(idA_, idB_, weight_);
	}
	void setEdge(int idA_, int idB_, double weight_=0){
		if(idA_>idB_){
			int idTmp;
			idTmp=idA_,idA_=idB_,idB_=idTmp;
		}
		idA=idA_, idB=idB_, weight=weight_;
	}
public:
	TopicNode *nodeA;
	TopicNode *nodeB;
};
class DirectedEdge : public Edge{
public:
	DirectedEdge(){}
	DirectedEdge(int idA_, int idB_, double weight_=0){
		setEdge(idA_, idB_,weight_);
	}
	void setEdge(int idStart, int idEnd, double weight_=0){
		idA=idStart, idB=idEnd;
		weight=weight_;
	}
public:
	Node *nodeA;
	Node *nodeB;
public:

};

#endif