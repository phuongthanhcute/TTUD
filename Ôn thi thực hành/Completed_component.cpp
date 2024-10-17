#include <bits/stdc++.h>
using namespace std;
//Just using BFS
int n,m;
const int maxx=200001;
bool visited[maxx];
set<int> E[maxx];
int res=0;
void bfs(int first){
    ++res;
    queue<int> Q;
    Q.push(first);
    visited[first]=true;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(auto v: E[u]){
            if(!visited[v]){
                visited[v]=true;
                Q.push(v);
                }
            }
        }
    }

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int u,v;
        scanf("%d %d", &u, &v);
        E[u].insert(v);
        E[v].insert(u);
    }

    fill_n(visited, n+1, false);
    for(int i=1;i<=n;i++){
        if(!visited[i]) bfs(i);
    }
    cout<<res;
    return 0;
}
