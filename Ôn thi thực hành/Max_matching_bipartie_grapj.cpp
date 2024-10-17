#include<bits/stdc++.h>
using namespace std;
// Connect[v] = u mean staff u do task v
int connect[10001] = {};
// Mean staff v has yet assigned task (visited[v] is in global, come[v] is in current for loop)
bool visited[10001] = {}, come[10001];
vector<int> s[10001];
bool findPath(int u){
    come[u] = false;
    for(int &v : s[u])
        if(!connect[v] || (come[connect[v]] && findPath(connect[v]))){
            visited[u] = true;
            connect[v] = u;
            return true;
        }
    return false;
}
int main(){
    int n, m, k, ti, num = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &ti);
            s[i].push_back(ti);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(register int j = 1; j <= m; ++j) come[j] = true;
        if(!visited[i] && findPath(i)) ++num;
    }
    cout << num;
}