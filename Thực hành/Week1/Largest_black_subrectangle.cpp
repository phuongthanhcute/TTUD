#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d", &a[i][j]);
        }
    }
}