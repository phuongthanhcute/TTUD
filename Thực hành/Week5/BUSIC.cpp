#include <bits/stdc++.h>

using namespace std;

const int MAX = 5010;
int n, k;
int D[MAX], C[MAX];
vector<vector<int>> adj; //lưu cạnh kề
int dist[MAX][MAX]; //khoảng cách bé nhất giữa 2 đỉnh u và v
int res[MAX], visited[MAX];

void inputData()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> C[i] >> D[i];
    }

    adj.resize(n + 1, vector<int>(0));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
 //tìm khoảng cách bé nhất giữa 2 đỉnh
void BFS(int source, int dist[])//dist: luu khoảng cách từ từ đỉnh đang xét tới các đỉnh khác
{
    queue<int> Q;
    Q.push(source);
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void calculate_dist()
{
    for (int u = 1; u <= n; ++u)
    {
        BFS(u, dist[u]);
    }
}

void dijkstra()
{
    for (int i = 0; i <= n; ++i)
    {
        res[i] = INT_MAX;
        visited[1] = 0;
    }

    res[1] = 0;
    int step = n;
    while (step--)
    {
        int u = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (visited[i] == 0 && res[u] > res[i])
            {
                u = i;
            }
        }
        if (u == 0)
            break;
        visited[u] = 1;
        for (int v = 1; v <= n; ++v)
        {
            if (dist[u][v] <= D[u])
            {
                res[v] = min(res[v], res[u] + C[u]);
            }
        }
    }
    cout << res[n] << endl;
}

int main()
{
    inputData();
    calculate_dist();
    dijkstra();
    return 0;
}