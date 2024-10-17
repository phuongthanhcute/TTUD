#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// sequence: chuỗi cần xét
// constraints: dsach ràng buộc
// distance: ma trận khoảng cách
int check(int n, vector<int> &sequence, vector<pair<int, int>> &precedence_constraints, vector<vector<int>> &distances)
{
    // Kiểm tra xem chuỗi có phải là một hoán vị của 1 đến n không
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < n; ++i)
    { // nếu đỉnh hiện tại <1 hoặc >n hoặc đã được thăm trước đó
        if (sequence[i] < 1 || sequence[i] > n || visited[sequence[i]])
        {
            return -1;
        }
        visited[sequence[i]] = true; // nếu không thì đánh dấu là đã thăm
    }

    // Kiểm tra ràng buộc về thứ tự
    for (auto &constraint : precedence_constraints)
    { // nếu dỉnh đầu tiên trong ràng buộc lại đứng sau đỉnh thứ 2 thì trả về false
        if (find(sequence.begin(), sequence.end(), constraint.first) > find(sequence.begin(), sequence.end(), constraint.second))
        {
            return -1;
        }
    }

    // Tính tổng khoảng cách đi lại
    int total_distance = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        total_distance += distances[sequence[i] - 1][sequence[i + 1] - 1];
    }
    total_distance += distances[sequence[n - 1] - 1][sequence[0] - 1]; // Quay lại điểm xuất phát
    return total_distance;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> sequence(n); //danh sách đường cần kiểm tra
    for (int i = 0; i < n; ++i)
    {
        cin >> sequence[i];
    }

    vector<vector<int>> distances(n, vector<int>(n)); //ma trận khoảng cách
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> distances[i][j];
        }
    }
    cin >> m; //số ràng buộc
    vector<pair<int, int>> precedence_constraints(m); //danh sách ràng buộc
    for (int k = 0; k < m; ++k)
    {
        cin >> precedence_constraints[k].first >> precedence_constraints[k].second;
    }
    // Kiểm tra khả thi và tính tổng khoảng cách
    int result = check(n, sequence, precedence_constraints, distances);
    // Xuất kết quả
    cout << result << endl;
    return 0;
}
