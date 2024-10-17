#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    //dp[i][j] số cách biểu diễn tổng j sử dụng i phần thử
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; ++j){
            for(int k=1; k*a[i-1]<=j; ++k){
                dp[i][j] += dp[i-1][j-k*a[i-1]];
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
