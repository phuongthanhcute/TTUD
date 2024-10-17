#include<bits/stdc++.h>
using namespace std;

int n,m, X[10005], Y[10005];
int dp[10005][10005];

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        cin>>X[i];
    }
    for(int j=1; j<=m; ++j){
        cin>>Y[j];
    }
    dp[0][1] = dp[1][0] = 0;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(X[i] == Y[j]) dp[i][j] = dp[i-1][j-1]+1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
}

