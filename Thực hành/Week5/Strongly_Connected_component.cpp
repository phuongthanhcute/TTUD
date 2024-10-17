#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int N;                                          // Số lượng đỉnh
    unordered_map<int, vector<int>> adj;            // Danh sách kề
    unordered_map<int, vector<int>> transposed_adj; // Danh sách kề của đồ thị chuyển

    Graph(int N) : N(N) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int v, vector<bool> &visited, stack<int> &finishStack)
    {
        visited[v] = true;
        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, visited, finishStack);
            }
        }
        finishStack.push(v);
    }

    void transposeGraph()
    {
        for (const auto &kvp : adj)
        {
            int u = kvp.first;
            for (int v : kvp.second)
            {
                transposed_adj[v].push_back(u);
            }
        }
    }

    void dfsTranspose(int v, vector<bool> &visited)
    {
        visited[v] = true;
        for (int neighbor : transposed_adj[v])
        {
            if (!visited[neighbor])
            {
                dfsTranspose(neighbor, visited);
            }
        }
    }

    int findSCCs()
    {
        stack<int> finishStack;
        vector<bool> visited(N + 1, false);

        // Bước 1: Thực hiện DFS trên đồ thị gốc để lấy thời gian hoàn thành
        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                dfs(i, visited, finishStack);
            }
        }

        // Bước 2: Chuyển đồ thị
        transposeGraph();

        // Bước 3: Thực hiện DFS trên đồ thị chuyển theo thời gian hoàn thành
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;

        while (!finishStack.empty())
        {
            int v = finishStack.top();
            finishStack.pop();
            if (!visited[v])
            {
                dfsTranspose(v, visited);
                ++sccCount;
            }
        }

        return sccCount;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << graph.findSCCs() << endl;

    return 0;
}

/* 
Thuật toán Kosaraju để tìm SCCs bao gồm ba bước chính:

Duyệt đồ thị ban đầu để tính thời gian hoàn thành (finishing time) của mỗi đỉnh.

Sử dụng DFS để duyệt đồ thị và ghi nhận thời gian hoàn thành của các đỉnh vào một ngăn xếp (stack).
Chuyển đồ thị (transpose graph).

Đảo ngược hướng của tất cả các cung trong đồ thị.
Duyệt đồ thị đã chuyển theo thứ tự giảm dần của thời gian hoàn thành từ bước 1.

Mỗi lần duyệt DFS trên đồ thị đã chuyển sẽ xác định một SCC.
*/