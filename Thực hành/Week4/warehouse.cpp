#include <bits/stdc++.h>
using namespace std;

int n, T, d, a[1002], t[1002];
int dp[1002][1002];
int res = 0;

int main()
{
    cin >> n >> T >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = t[i]; j <= T; ++j)
        {
            for (int k = max(0, i - d); k <= i - 1; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[k][j - t[i]] + a[i]);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
}