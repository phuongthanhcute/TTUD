#include<bits/stdc++.h>
using namespace std;

// tim cach doi m dong thanh cac dong xu menh gia a[i]
int m, n, a[1005];

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int> dp(m+1);
    dp[0] = 1;
    for(int i=0; i<n; ++i){
        for(int j=1; j<=m; ++j){
            if(j>=a[i]) dp[j] += dp[j-a[i]];
        }
    }
    cout<<dp[m];
}
