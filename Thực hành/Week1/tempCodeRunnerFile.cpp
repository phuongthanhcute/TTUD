#include <bits/stdc++.h>
using namespace std;

int n,m,r,c, p=-1, k=0, ktra=0;
int a[1000][1000]={};
bool visited[1000][1000]={};
int step=0;

struct node{
    int i,j,step;
    node(int i1, int j1, int step1){
        i = i1;
        j = j1;
        step = step1;
    }
};

node *x[1000001];

void Try(int i,int j){
    if(!a[i][j] && !visited[i][j]){
        x[++k] = new node(i, j, x[p]->step + 1);
        visited[i][j] = true;
    }
    if(i > n || j > m || !i || !j)
        ktra = x[k]->step;
}
int main(){
    //Nhap du lieu
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%d", &a[i][j]);
        }
    }
    if(a[r][c])
        cout << -1;
    else{
        x[0] = new node(r, c, 0);
        while(++p <= k && !ktra){
            int i = x[p]->i, j = x[p]->j;
            Try(i - 1, j);
            Try(i, j - 1);
            Try(i + 1, j);
            Try(i, j + 1);
        }
        if(ktra)
            cout << ktra;
        else
            cout << -1;
    }
}