#include <iostream>
using namespace std;

vector<int> bfs(vector<vector<int>> adj){
    int n = adj.size();
    if(n==0) return {};

    vector<int> ans;

    queue<int> q;
    vector<int> visited(n, 0);

    q.push(0); //0indexed
    visited[0] = 1;

    while(!q.empty()){
        int Node = q.front();
        q.pop();
        ans.push_back(Node);

        for(auto it: adj[Node]){
            if(!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;

}


int main()
{
    return 0;
}