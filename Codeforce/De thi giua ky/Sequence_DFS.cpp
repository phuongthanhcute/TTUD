#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> Edges(m);

void DFS(vector<vector<int>> &Edges, vector<bool> &visited, vector<int> &res, int u)
{
    visited[u] = true;
    res.push_back(u);
    for (int v : Edges[u])
    {
        if(!visited[v]) DFS(Edges, visited, res, v);
    }
}
    int main()
    {
        cin >> n >> m;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            Edges[u].push_back(v);
            Edges[v].push_back(u);
        }
        vector<bool> visited(n+1, false);
        vector<int> res;
        DFS(Edges, visited, res, 1);
        for(int i: res){
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }