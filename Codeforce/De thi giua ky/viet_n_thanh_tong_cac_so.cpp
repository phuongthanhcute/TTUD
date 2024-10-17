#include <bits/stdc++.h>
using namespace std;
// bài toán đếm số cách viết n thành tổng các số nguyên dương

const int mod = 1000000007;
int Try(int n)
{
    vector<int> dp(n + 1, 0); // dp[i]: so cách viết i thành tổng các số nguyên dương
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[j] = (dp[j-i] + dp[j]) % mod;
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    cout << Try(n);
    return 0;
}