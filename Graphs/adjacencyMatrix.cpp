/*
Code to build adjacency matrix
*/


/*
Parameters
1. n = no. nodes
2. m = no. edges
*/
vector<vector<int> > adjacencyMatrix(int n, int m){ 
    int x, y;
    vector<vector<int> > graph = vector<vector<int> >(n); // graph data structure
    for (int i = 0; i<m; i++){
        cin >> x;
        cin >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return graph;
}
