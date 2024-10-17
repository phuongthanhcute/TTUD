#include <bits/stdc++.h>
using namespace std;

int n, m;
int res = 0;
int d[10001];
int c[10001]={}, a[10001]={};
vector<int> v[10001];
queue<int> Q;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin>>d[i];
    for (int i = 0; i < m; ++i)
    {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
        ++c[tmp1];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 0)
        {
            Q.push(i);
            a[i] = d[i];
        }
    }

    while (!Q.empty())
    {
        int i = Q.front();
        Q.pop();
        for (int j : v[i])
        {
            a[j] = max(a[i]+d[j], a[j]);
            res = max(res, a[j]);
            if(--c[j]==0) Q.push(j);
        }
    }
    cout<<res;
    return 0;
}