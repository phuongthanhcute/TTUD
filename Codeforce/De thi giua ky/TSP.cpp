//tsp
#include <bits/stdc++.h>
using namespace std;

int n;
int c[30][30];
int res = 1e9, currDist = 0;
int step[30];
bool visited[30];

void Try(int k){
    int currCity = step[k-1];
    if(k==n){
        res = min(currDist + c[currCity][0], res);
    }

    for(int i=1; i<n; ++i){
        if(!visited[i]){
            int cost = c[currCity][i];
            if(currDist + cost < res){
                step[k] = i;
                visited[i] = true;
                currDist += cost;
                Try(k+1);
                visited[i] = false;
                currDist -= cost;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>c[i][j];
        }
    }
    Try(1);
    cout<<res;
}