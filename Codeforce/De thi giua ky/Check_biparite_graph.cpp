#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &graph, int n)
{
    vector<int> color(n+1, -1); // đánh dấu chưa đỉnh nào được tô màu

    // bfs
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : graph[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> Edges(n+1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    if (check(Edges, n))
        cout << 1;
    else
        cout << 0;
    return 0;
}
