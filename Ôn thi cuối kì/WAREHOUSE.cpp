// warehouse

#include <bits/stdc++.h>
using namespace std;

int n, T, D;
int a[1005], t[1005], res = 0;
int dp[1002][1002]; // dp[i][j] trọng lượng hàng đã lấy cho tới thời gian j và khoảng cách i
int main()
{
    cin >> n >> T >> D;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = t[i]; j <= T; ++j)
        {
            for (int k = max(0, i - D); k <= i - 1; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[k][j - t[i]] + a[i]);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}