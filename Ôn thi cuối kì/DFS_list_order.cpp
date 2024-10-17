#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj(100005);
vector<bool> visited(100005, false);
void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &res, int u){
    visited[u] = true;
    res.push_back(u);
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(adj, visited, res, v);
        }
    }
}
int main(){
    cin>>n>>m;
    for( int i=0; i<m; ++i){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res;
    dfs(adj, visited, res, 1 );
    for(int i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}