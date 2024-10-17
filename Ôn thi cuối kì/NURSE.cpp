#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, k1, k2;
int dp[1005]={};//số cách xếp cho i ngày đầu tiên
int main() {
    cin >> n >> k1 >> k2;
    ++k2;
    for(int i=++k1; i<=k2; ++i){
        dp[i] = 1;
    }
    for (int i= k2+1; i<=n+1; ++i){
        for(int j=k1; j<=k2; ++j){
            dp[i] = (dp[i] + dp[i-j])% MOD;
        }
    }

    cout<< dp[n-1] + 2*dp[n] + dp[n+1];
    return 0;
}
