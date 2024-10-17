#include <bits/stdc++.h>
using namespace std;

string p, t;
int last[260];

void computeLast(string p)
{
    for (int c = 0; c <= 255; ++c)
        last[c] = 0;
    int k = p.length();
    for (int i = k - 1; i >= 0; --i)
    {
        if (last[p[i]] == 0)
            last[p[i]] = i;
    }
}

int solve(string t, string p)
{
    computeLast(p);
    int s = 0, cnt = 0;
    int n = t.length(), m = p.length();
    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && t[j + s] == p[j])
        {
            --j;
        }
        if (j == -1)
        {
            cnt++;
            s++;
        }
        else
        {
            int k = last[t[j + s]];
            s = s + (j - k > 1 ? j - k : 1);
        }
    }
    return cnt;
}

int main()
{
    getline(cin, p);
    getline(cin, t);

    int res = solve(t, p);
    cout << res;
    return 0;
}
