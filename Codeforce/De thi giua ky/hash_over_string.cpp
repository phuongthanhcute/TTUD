#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int base = 256;
int hashh(const string &S, int m)
{
    int res = 0;
    int k = S.length();
    for (int i = 0; i < k; ++i)
    {
        res = (1LL * res * base % m + S[i]) % m;
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++)
    {
        int hascode = hashh(S[i], m);
        cout << hascode << endl;
    }
}