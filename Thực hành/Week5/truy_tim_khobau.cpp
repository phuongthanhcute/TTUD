#include <bits/stdc++.h>
using namespace std;

struct Cells
{
    int x, y, val;
};

bool compare(Cells a, Cells b)
{
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int main()
{
    int n;
    cin >> n;
    vector<Cells> cells(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cells[i].x >> cells[i].y >> cells[i].val;
    }
    sort(cells.begin(), cells.end(), compare);
    vector<long long> dp(n); // tổng lượng kho báu thu được khi đi tới ô thứ i
    dp[0] = cells[0].val;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = cells[i].val;
        for (int j = 0; j < i; ++j)
        {
            if ( cells[i].y >= cells[j].y)
            {
                dp[i] = max(dp[i], dp[j] + cells[i].val);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}