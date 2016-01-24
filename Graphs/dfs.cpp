#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
DFS (depth first search)
 
 Parameters
 1. s = source node
 2. t = destination
 2. vector<node>* nodes = vector of all nodes, which gives access to information on parent and visited.
 3. vector<vector<int>> g = adjacency matrix of graph
 
 Notes:
 1. Not Tested
 */

struct node{
	int parent;
	bool visited = false;
};



// recursive DFS
/*
 In this version, we maintain a global nodes data structure to track which nodes are reachable by s.
 After the recursive dfs procedure ends, we simply check if t was visited.
 */
void dfs(int s, vector<node>* nodes, vector<vector<int> >* g){
	(*nodes)[s].visited = true;
	for (auto neighbor: (*g)[s]){
		if (!(*nodes)[neighbor].visited)
			dfs(neighbor,vector<node>* nodes, vector<vector<int> >* g);
	}
}



// iterative DFS
/* In this version, we terminate early if t is found. */

void dfs(int s, int t, vector<node>* nodes, vector<vector<int> >* g){
	
	bool pathExists = false;
	vector<int> path;
	int current = s;
	(*nodes)[current].parent = -1; // set parent as dummy value (-1)
	stack<int> S;
	S.push(current);
	
	// DFS algorithm
	while (!S.empty()){
		current = S.top();
		S.pop();
		
		if (!*nodes[current].visited){
			*nodes[current].visited = true;
			for (auto neighbor: (*g)[current]){ // add all incident vertices
				S.push(neighbor);
				*nodes[neighbor].parent = current;
				if (neighbor == t){pathExists = true;}
			}
		}
		
		// record path
	    if (pathExists){
			int cur = t;
			while (cur != -1){
				path.push_back(cur);
				cur = (*nodes)[cur].parent;
			}
			break;
		}
	}
	return;
}