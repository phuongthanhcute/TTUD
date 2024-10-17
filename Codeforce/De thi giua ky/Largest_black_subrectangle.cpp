#include <bits/stdc++.h>

using namespace std;

//heights[j]: số ô đen liên tiếp trở về trước tính từ ô j
// Hàm tính diện tích hình chữ nhật lớn nhất trong biểu đồ histogram
int Sngang(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int index = 0;
    int n = heights.size();

    while (index < n) {
        if (s.empty() || heights[s.top()] <= heights[index]) {
            s.push(index++);
        } else {
            int top = s.top();
            s.pop();
            int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int area = heights[top] * (s.empty() ? index : index - s.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Hàm tính diện tích hình chữ nhật đen lớn nhất trong ma trận nhị phân
int Smax(vector<vector<int>>& matrix, int n, int m) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    vector<int> heights(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            heights[j] = matrix[i][j] == 1 ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, Sngang(heights));
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = Smax(matrix, n, m);
    cout << result << endl;

    return 0;
}
