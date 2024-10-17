#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005; // Giới hạn số đỉnh tối đa

vector<int> adj[MAXN]; // Danh sách kề của đồ thị
int disc[MAXN]; // Mảng lưu thời gian khám phá của các đỉnh
int low[MAXN]; // Mảng lưu giá trị low của các đỉnh
int parent[MAXN]; // Mảng lưu cha của mỗi đỉnh trong cây DFS
bool visited[MAXN]; // Mảng đánh dấu các đỉnh đã được thăm
bool articulationPoint[MAXN]; // Mảng đánh dấu các điểm khớp
int timeCounter; // Biến đếm thời gian khám phá
int articulationCount; // Đếm số lượng điểm khớp
int bridgeCount; // Đếm số lượng cầu

// Hàm DFS để duyệt đồ thị và tìm các điểm khớp và cầu
void dfs(int u) {
    visited[u] = true; // Đánh dấu đỉnh u đã được thăm
    disc[u] = low[u] = ++timeCounter; // Đặt thời gian khám phá và giá trị low ban đầu của đỉnh u
    int children = 0; // Đếm số lượng con của đỉnh u trong cây DFS
    // Duyệt qua tất cả các đỉnh kề của u
    for (int v : adj[u]) {
        if (!visited[v]) { // Nếu đỉnh v chưa được thăm
            children++;
            parent[v] = u; // Đặt cha của v là u
            dfs(v); // Đệ quy duyệt từ đỉnh v
            // Cập nhật giá trị low của u dựa trên giá trị low của v
            low[u] = min(low[u], low[v]);
            // Kiểm tra điều kiện để xác định điểm khớp
            if (parent[u] == -1 && children > 1) { // Nếu u là gốc và có ít nhất hai con
                articulationPoint[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u]) { // Nếu u không phải là gốc và low[v] >= disc[u]
                articulationPoint[u] = true;
            }
            // Kiểm tra điều kiện để xác định cầu
            if (low[v] > disc[u]) {
                bridgeCount++;
            }
        } else if (v != parent[u]) { // Nếu v đã được thăm và v không phải là cha của u
            // Cập nhật giá trị low của u cho trường hợp cạnh ngược
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Hàm tìm và đếm số lượng điểm khớp và cầu
void findArticulationPointsAndBridges(int N) {
    timeCounter = 0; // Đặt lại biến đếm thời gian
    articulationCount = 0; // Đặt lại số lượng điểm khớp
    bridgeCount = 0; // Đặt lại số lượng cầu
    // Khởi tạo các mảng
    fill(disc, disc + N + 1, -1);
    fill(low, low + N + 1, -1);
    fill(parent, parent + N + 1, -1);
    fill(visited, visited + N + 1, false);
    fill(articulationPoint, articulationPoint + N + 1, false);
    // Duyệt qua tất cả các đỉnh để tìm điểm khớp và cầu
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    // Đếm số lượng điểm khớp
    for (int i = 1; i <= N; i++) {
        if (articulationPoint[i]) {
            articulationCount++;
        }
    }
}

int main() {
    int N, M; // Số đỉnh và số cạnh
    cin >> N >> M;
    // Đọc các cạnh và thêm vào danh sách kề
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Tìm và đếm số lượng điểm khớp và cầu
    findArticulationPointsAndBridges(N);
    // In kết quả
    cout << articulationCount << " " << bridgeCount << endl;
    return 0;
}

/*
Khái niệm disc và low
disc[u] (discovery time) là thời điểm mà đỉnh u được thăm lần đầu tiên trong quá trình duyệt DFS. Đây là một giá trị duy nhất cho mỗi đỉnh, được gán trong quá trình duyệt.
low[u] là giá trị nhỏ nhất của disc mà đỉnh u có thể đạt được bằng cách đi qua các cạnh ngược hoặc cạnh tiến. Nó cho biết thời điểm nhỏ nhất mà đỉnh u hoặc một trong những đỉnh con của nó có thể quay lại đến một trong các tổ tiên của u.
Vai trò của disc và low trong việc tìm điểm khớp và cầu
Điểm khớp (Articulation Points)
Một đỉnh u là điểm khớp nếu:
u là gốc của DFS và có ít nhất hai con (cây DFS bị chia làm hai thành phần khi u bị loại bỏ).
u không phải là gốc của DFS nhưng có một đỉnh con v mà không thể quay lại tổ tiên của u hoặc u qua bất kỳ cạnh nào khác ngoài u-v (tức là low[v] >= disc[u]).
Cầu (Bridges)
Một cạnh u-v là cầu nếu:
low[v] > disc[u], tức là không có cách nào từ v quay lại được u hoặc tổ tiên của u mà không đi qua cạnh u-v.
*/