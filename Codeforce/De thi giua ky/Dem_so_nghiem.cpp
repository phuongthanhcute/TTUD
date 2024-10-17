#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    //dp[i][j]: số cách biểu diễn tổng j sử dụng i phần tử
    vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= M; ++j) {
            for (int k = 1; k * a[i - 1] <= j; ++k) {
                dp[i][j] += dp[i - 1][j - k * a[i - 1]];
            }
        }
    }

    cout << dp[n][M] << endl;

    return 0;
}
