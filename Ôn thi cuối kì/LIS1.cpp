#include <bits/stdc++.h>
using namespace std;

int Solve(vector<int>& a) {
    int n = a.size();
    if (n <= 1) return n;

    vector<int> lis;
    lis.push_back(a[0]);

    for (int i = 1; i < n; ++i) {
        if (a[i] > lis.back()) {
            lis.push_back(a[i]);
        } else if (a[i] < lis.back() && a[i] > lis[lis.size() - 2]) {
            *lower_bound(lis.begin(), lis.end() - 1, a[i]) = a[i];
        }
    }

    return lis.size();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int result = Solve(a);
        cout << result << endl;
    }

    return 0;
}
