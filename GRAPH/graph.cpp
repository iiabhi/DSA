#include <iostream>
using namespace std;
int main()
{

    int n, m;
    cin>>n>>m;

    //graph here
    int adj[n+1][n+1];  ///adjancy matrix(1-indexed)
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //adjacency list
    vector<int> adjList[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return 0;
}