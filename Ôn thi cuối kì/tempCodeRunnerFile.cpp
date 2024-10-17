#include <bits/stdc++.h>
using namespace std;

int n, c[40][40], x[40], cmin=99999,currDist = 0, res = 1e9;
int visited[40]={};

void Try(int k){
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            visited[i] = 1;
            currDist += c[x[k-1]][i] + c[i][i+n];
            x[k] = i+n;
            if(k==n) res = min(res, currDist + c[x[k]][0]);
            else{
                if(currDist +cmin*(2*n+1-k) < res) Try(k+1);
            } 
            visited[i] = 0;
            currDist -=  c[x[k-1]][i] + c[i][i+n];
        }
    }
}
int main(){
    cin>>n;
    for(int i=0; i<2*n+1; i++){
        for(int j=0; j<2*n+1; j++){
            cin>>c[i][j];
            if(c[i][j] <= cmin) cmin=c[i][j];
        }
    }
    x[0] = 0;
    Try(1);
    cout<<res;
}