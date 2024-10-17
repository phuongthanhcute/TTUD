#include <bits/stdc++.h>
using namespace std;

int n, w[1000006];
vector<int> adj[1000006];
int dp[1000006][2]; //dp[u][0]: tổng trọng số khi không chọn u, bằng 1 là có chọn

void dfs(int u, int par){
    dp[u][0] = 0;
    dp[u][1] = w[u];

    for(int v: adj[u]){
        if(v == par) continue;
        dfs(v,u);
        dp[u][0]  += max(dp[v][0], dp[v][1]);
        dp[u][1] +=dp[v][0];
    }
}
int main(){
    int u,v;
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>w[i];
    }
    for(int i=1; i<=n-1; ++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<max(dp[1][0], dp[1][1]);
    return 0;
}