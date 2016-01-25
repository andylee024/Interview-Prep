#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct Node{
	bool visited = false;
	bool tmp = false;
};

/***********************************
Topological Sort (DFS implementation) 
************************************/ 

void visit(int v, vector<Node> &nodes, unordered_set<int> &unvisitedNodes, vector<vector<int> >* graph, stack<int> &S){
	if(nodes[v].tmp){
		printf("ERROR: Cycle detected");
		return;
	}
	
	if (!nodes[v].visited){
		nodes[v].tmp = true;
		for(int neighbor: (*graph)[v] ){
			visit(neighbor, nodes, unvisitedNodes, graph, S);
		}
		nodes[v].visited = true;
		nodes[v].tmp = false;
		unvisitedNodes.erase(v);
		S.push(v);
	}
}

/*
Given adjacency representation of graph, returns topological sort using Tarjan's algorithm which uses DFS implementation. 
*/
vector<int> TopologicalSort(vector<vector<int> >* graph){
	
	// Initialization
	int n = (*graph).size();
	vector<Node> nodes(n); // contains information about visited status of nodes
	unordered_set<int> unvisitedNodes; // maintains set of unvisited nodes
	for (int i=0; i<n; i++){unvisitedNodes.insert(i);}
	stack<int> S; // data structure to record topological ordering
	
	// Topological sort algorithm
	while (!unvisitedNodes.empty()){
		unordered_set<int>::iterator a = unvisitedNodes.begin(); // select unmarked node
		int v = *a;
		visit(v, nodes, unvisitedNodes, graph, S); // visit node
	}
	
	// record topological ordering in list
	vector<int> L;
	while (!S.empty()){ L.push_back(S.top()); S.pop();}
	return L;
}
