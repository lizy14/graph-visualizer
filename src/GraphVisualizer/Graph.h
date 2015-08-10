#ifndef GRAPH_H
#define GRAPH_H

class Graph_;
#include "Edge.h"
#include "Node.h"
#include <ogdf/basic/Graph.h>
#include <string>
#include <vector>
#include <QMessageBox>
using std::string;
using std::vector;

class Graph_{
	virtual void importNodesFromTXT(string fileName)=0;
	virtual void importEdgesFromTXT(string fileName)=0;
	virtual void doLayout()=0;
	virtual void bind()=0;

};

class PaperConferenceAuthorGraph : Graph_{
public:
	vector<PaperNode> papers;
	vector<ConferenceNode> conferences;
	vector<AuthorNode> authors;
	vector<DirectedEdge> edges;

	vector<Node*> nodes;
	void makeUnionNodeVector(){
		nodes.clear();
		int n;
		n=papers.size();
		for(int i=0; i<n; i++){
			nodes.push_back(&papers[i]);
		}
		n=authors.size();
		for(int i=0; i<n; i++){
			nodes.push_back(&authors[i]);
		}
		n=conferences.size();
		for(int i=0; i<n; i++){
			nodes.push_back(&conferences[i]);
		}
	}
	void importNodesFromTXT(string fileName);
	void importEdgesFromTXT(string fileName);
	void doLayout();

	int calcDegree();//计算各顶点的连通度，并返回其中的最大值
	void bind();//将顶点和边关联起来
	Node* getNode(int id){
		for(Node* pNode:nodes){
			if(pNode->id==id)
				return pNode;
		}
	}
	bool isConnected(int idA, int idB){
		for(DirectedEdge i:edges){
			if(i.idA==idA && i.idB==idB)
				return true;
			if(i.idA==idB && i.idB==idA)
				return true;

		}
		return false;
	}
};
class TopicGraph : Graph_{
public:
	vector<TopicNode> topics;
	vector<UndirectedEdge> edges;
	
	void importNodesFromTXT(string fileName);
	void importEdgesFromTXT(string fileName);
	void doLayout();
	TopicNode* getNode(int id){
		int n=topics.size();
		for(int i=0; i<n; i++){
			if(topics[i].id == id)
				return &topics[i];
		}
	}
	int calcDegree();//计算各顶点的连通度，并返回其中的最大值
	void bind();//将顶点和边关联起来：维护边中指向节点的指针
	
	//return weight if connected; 0 if unconnected; 1 if a==b
	double isConnected(int indexA, int indexB){
		for(UndirectedEdge i : edges){
			if(
				((i.idA==topics[indexA].id)
				&&(i.idB==topics[indexB].id))
				||
				((i.idA==topics[indexB].id)
				&&(i.idB==topics[indexA].id)))
				return i.weight;
		}
		return indexA==indexB;
	}

};

#endif