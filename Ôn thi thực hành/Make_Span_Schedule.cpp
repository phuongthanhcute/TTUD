#include<bits/stdc++.h>
using namespace std;
int n, m, d[10001];
int res = 0;
int c[10001] = {}; //c[i] lưu số đỉnh cha của i
int a[10001] = {}; //a[i] Lưu độ dài đường đi dài nhất từ gốc tới đỉnh i
vector<int> v[10001];
queue<int> q;
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> d[i];
    for(int i=0; i<m; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
        ++c[tmp1];
    }
    
    for(int i=1; i<=n; ++i){
        if(c[i]==0){
            q.push(i);
            a[i] = d[i];
        }
    }

    while(q.empty() == false){
        int i= q.front();
        q.pop();
        for(int j : v[i]){
            a[j] = max(a[i]+d[j], a[j]);
            res = max(res,a[j]);
            if(--c[j]==0) q.push(j);
        }
    }
    cout<<res;
    return 0;
}