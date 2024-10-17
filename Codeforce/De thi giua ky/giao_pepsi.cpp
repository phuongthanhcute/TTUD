#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

//chưa làm xong, khó quá
struct Edge {
    int to;
    int distance;
};

vector<vector<Edge>> graph;
vector<vector<int>> dp;
vector<int> demand;
vector<pair<int, int>> forbidden;
int n, Q, K;

// Dijkstra's algorithm to find shortest paths from source to all nodes
vector<int> dijkstra(int source) {
    vector<int> dist(n + 1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.distance;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Dynamic programming to find minimum distance for each truck to serve a subset of customers
int solve(int truck, int mask) {
    if (mask == 0) return 0;
    if (dp[truck][mask] != -1) return dp[truck][mask];

    int ans = INF;
    for (int subset = mask; subset; subset = (subset - 1) & mask) {
        if ((mask & subset) == subset) {
            int remaining = mask ^ subset;
            bool valid = true;
            for (auto& [u, v] : forbidden) {
                if ((subset & (1 << u)) && (subset & (1 << v))) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            int next_truck = solve(truck + 1, remaining);
            int current_dist = 0;
            for (int i = 1; i <= n; ++i) {
                if (subset & (1 << i)) {
                    current_dist += dijkstra(0)[i];
                }
            }
            ans = min(ans, max(current_dist, next_truck));
        }
    }

    return dp[truck][mask] = ans;
}

int main() {
    cin >> n >> K >> Q;

    graph.resize(n + 1);
    dp.assign(K + 1, vector<int>(1 << (n + 1), -1));
    demand.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> demand[i];
    }

    for (int i = 0; i < K; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int M;
    cin >> M;
    forbidden.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> forbidden[i].first >> forbidden[i].second;
    }

    int total_distance = solve(0, (1 << (n + 1)) - 1);
    cout << total_distance << endl;

    return 0;
}
