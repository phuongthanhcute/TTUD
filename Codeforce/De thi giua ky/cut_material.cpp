#include <bits/stdc++.h>
using namespace std;

//cắt vật liệu 
int H, W, n; // Kích thước của hình chữ nhật lớn (H x W) và số lượng hình chữ nhật con
int h[11], w[11]; // Mảng lưu chiều cao và chiều rộng của các hình chữ nhật con
int mark[11][11] = {}; // Ma trận đánh dấu các vị trí đã được sử dụng trên lưới
int x[11], y[11], o[11]; // Mảng lưu vị trí và hướng đặt của các hình chữ nhật con (x,y) là tọa độ điểm trên cùng bên trái
bool found_solution = false; // Biến đánh dấu nếu đã tìm thấy giải pháp

// Hàm nhập dữ liệu
void input() {
    cin >> H >> W; // Nhập kích thước của hình chữ nhật lớn
    cin >> n; // Nhập số lượng hình chữ nhật con
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> w[i]; // Nhập chiều cao và chiều rộng của từng hình chữ nhật con
    }
}
// Hàm đánh dấu hoặc xóa đánh dấu các vị trí trên lưới, mark_value = 0 (nếu chưa đặt) hoặc 1(nếu đã đặt)
void doMark(int vx, int vy, int vo, int k, int mark_value) {
    int wk = w[k]; // Chiều rộng của hình chữ nhật con
    int hk = h[k]; // Chiều cao của hình chữ nhật con
    if (vo == 1) {
        // Nếu hướng đặt là ngang, đổi chiều rộng và chiều cao
        wk = h[k];
        hk = w[k];
    }
    // Đánh dấu những ô đã đặt hình chữ nhật con vào
    for (int i = vx; i <= vx + hk - 1; ++i) {
        for (int j = vy; j <= vy + wk - 1; ++j) {
            mark[i][j] = mark_value;
        }
    }
}
// Hàm kiểm tra xem có thể đặt hình chữ nhật con tại vị trí (vx, vy) với hướng vo không
bool check(int vo, int vx, int vy, int k) {
    int wk = w[k];
    int hk = h[k];
    if (vo == 1) {
        wk = h[k];
        hk = w[k];
    }
    // Kiểm tra nếu vượt quá biên của hình chữ nhật lớn
    if (vx + hk > H || vy + wk > W) return false;
    // Kiểm tra nếu các vị trí đã bị đánh dấu (đã sử dụng)
    for (int i = vx; i <= vx + hk - 1; ++i) {
        for (int j = vy; j <= vy + wk - 1; ++j) {
            if (mark[i][j]) return false;
        }
    }
    return true;
}
// Hàm thử đặt các hình chữ nhật con (backtracking)
void Try(int k) {
    if (k == n) {
        // Nếu đã đặt hết các hình chữ nhật con, thiết lập biến đánh dấu và trả về
        found_solution = true;
        return;
    }
    // Thử cả hai hướng đặt (dọc và ngang)
    for (int vo = 0; vo <= 1; ++vo) {
        int wk = w[k];
        int hk = h[k];
        if (vo == 1) {
            wk = h[k];
            hk = w[k];
        }
        // Thử tất cả các vị trí trên lưới
        for (int vx = 0; vx <= H - hk; ++vx) {
            for (int vy = 0; vy <= W - wk; ++vy) {
                if (check(vo, vx, vy, k)) {
                    // Nếu vị trí hợp lệ, đánh dấu và thử tiếp với hình chữ nhật con tiếp theo
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(vx, vy, vo, k, 1);
                    Try(k + 1);
                    if (found_solution) return;
                    // Xóa đánh dấu nếu không tìm thấy giải pháp
                    doMark(vx, vy, vo, k, 0);
                }
            }
        }
    }
}
// Hàm Solve gọi hàm Try và in kết quả
void Solve() {
    found_solution = false; // Khởi tạo biến đánh dấu chưa tìm thấy giải pháp
    Try(0); // Bắt đầu thử từ hình chữ nhật con đầu tiên
    if (found_solution)
        cout << 1 << endl; // In 1 nếu tìm thấy giải pháp
    else
        cout << 0 << endl; // In 0 nếu không tìm thấy giải pháp
}

int main() {
    input(); // Nhập dữ liệu
    Solve(); // Giải bài toán
}

