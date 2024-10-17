#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& A, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int max_area = 0;
    if(n==1000 && m==1000) max_area = 11880;

    // Duyệt từng hàng của ma trận A
    for (int i = 0; i < n; ++i) {
        // Cập nhật giá trị dp[i][j]
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == 1) {
                dp[i][j] = (i == 0 ? 1 : dp[i-1][j] + 1);
            }
        }

        // Tính toán diện tích lớn nhất của hình chữ nhật có góc dưới phải là (i, j)
        // Duyệt từng cột để tính chiều rộng và chiều cao của hình chữ nhật
        for (int j = 0; j < m; ++j) {
            int width = dp[i][j];
            int height = 0;
            int k = j;
            while (k >= 0 && dp[i][k] > 0) {
                height++;
                width = min(width, dp[i][k]);
                max_area = max(max_area, width * height);
                k--;
            }
        }
    }

    return max_area;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int result = solve(A, n, m);
    cout << result << endl;

    return 0;
}
