#include <bits/stdc++.h>

using namespace std;

int check_route(int n, vector<int>& route, vector<vector<int>>& distances, vector<pair<int, int>>& constraints) {
    //xây dựng đồ thị có hướng (ràng buộc thứ tự ưu tiên)
    unordered_map<int, vector<int>> graph; //mỗi key là 1 điểm i, giá trị tương ứng là vector chứa các điểm i nằm trước điểm j
    unordered_map<int, int> in_degree; //key là điểm i, giá trị là số lượng điểm có ràng buộc đứng sau điểm i
    
    for (auto& constraint : constraints) {
        int i = constraint.first;
        int j = constraint.second;
        graph[i].push_back(j);
        in_degree[j]++;
    }
    
    // kiểm tra xem rout có thỏa mãn không
    unordered_map<int, int> position; //lưu vị trí từng điểm trong route
    for (int i = 0; i < n; ++i) {
        position[route[i]] = i;
    }
    
    for (auto& [i, neighbors] : graph) {
        for (int j : neighbors) {
            if (position[i] >= position[j]) {
                return -1;
            }
        }
    }
    
    // tính tổng quãng đường di chuyển
    int total_distance = 0;
    for (int i = 0; i < n - 1; ++i) {
        total_distance += distances[route[i] - 1][route[i + 1] - 1];
    }
    total_distance += distances[route[n - 1] - 1][route[0] - 1]; // return to start point
    
    return total_distance;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> route(n);
    for (int i = 0; i < n; ++i) {
        cin >> route[i];
    }
    
    vector<vector<int>> distances(n, vector<int>(n)); //khoang cach tu diem i+1 den j+1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distances[i][j];
        }
    }
    
    int m;
    cin >> m;
    
    vector<pair<int, int>> constraints(m);
    for (int i = 0; i < m; ++i) {
        cin >> constraints[i].first >> constraints[i].second;
    }
    
    int result = check_route(n, route, distances, constraints);
    cout << result;
    
    return 0;
}
