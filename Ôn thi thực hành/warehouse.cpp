#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int n,T,D;
int a[maxn];
int t[maxn];
int dp[maxn][maxn]; // dp[i][j] lượng hàng tối đa thu được khi kết thúc tại điểm i và maatss lượng thời gian là j
int main(){
    cin>>n>>T>>D;
    int res = 0;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    for(int i=1; i<=n; ++i){
        cin>>t[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j= t[i]; j<=T; ++j){
            for(int k = max(0, i-D); k<=i-1; ++k ){
                dp[i][j] = max(dp[i][j], dp[k][j-t[i]]+a[i]);
            }
            res =  max(res, dp[i][j]);
        }
    }
}