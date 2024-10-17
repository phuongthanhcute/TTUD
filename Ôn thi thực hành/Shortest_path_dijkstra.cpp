#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PAIR;
vector<int> dist; //luu khoang cach tu goc toi dinh i
vector<vector<PAIR>> adj; //Luu canh ke: adj[u]={v, w}

void dijkstra(int head){
    //pq: lưu cặp chi phí nhỏ nhất cho tới i và đỉnh i
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    pq.push({0, head});
    dist[head] = 0;
    while(!pq.empty()) {
        int d = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(d > dist[x]) continue;
        for( auto &y: adj[x]){
            int v = y.first;
            int w = y.second;
            if(dist[x] + w < dist[v]){
                dist[v] = dist[x]+w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main(){
    int n, m, x, y, w, s, t;
    //freopen("test.txt", "r", stdin);
    cin>>n>>m;
    dist.assign(n+1, 1000000);
    adj.assign(n+1, vector<PAIR>());
    for(int i=0; i<m; ++i){
        cin>>x>>y>>w;
        adj[x].push_back({y, w});
    }
    
    cin>>s>>t;
    dijkstra(s);
    if(dist[t]==1000000) cout<<-1<<endl;
    else cout<<dist[t];
    return 0;

}