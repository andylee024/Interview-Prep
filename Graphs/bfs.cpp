#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
 BFS (Breadth First Search):
 
 Notes:
 1. Algorithm is mostly correct, but needs to be rigorously tested for completeness, especially last part with path creation.
 */

struct node{
	int parent;
	bool visited = false;
};

/*
 Parameters
 1. s = source node
 2. t = destination
 2. vector<node>* nodes = vector of all nodes, which gives access to information on parent and visited.
 3. vector<vector<int>> g = adjacency matrix of graph
 */

void bfs(int s, int t, vector<node>* nodes, vector<vector<int> >* g){
	
	bool pathExists = false;
	vector<int> path;
	
	// initialization
	int current = s;
	queue<int> Q;
	(*nodes)[current].visited = true;
	(*nodes)[current].parent = -1; // set parent as dummy value
	Q.push(current);
	
	// BFS algorithm
	while (!Q.empty()){
		current = Q.front();
		Q.pop();
		
		// push unvisited neighbors
		for (auto neighbor: (*g)[current]){
			if ((*nodes)[neighbor].visited == false){
				Q.push(neighbor);
				(*nodes)[neighbor].visited = true;
				(*nodes)[neighbor].parent = current;
				
				if (neighbor == t){
					pathExists = true;
					break;
				}
			}
		}
		
		// record shortest path
		if (pathExists){
			int cur = t;
			while (cur != -1){
				path.push_back(cur);
				cur = (*nodes)[cur].parent;
			}
		}
	}
	return;