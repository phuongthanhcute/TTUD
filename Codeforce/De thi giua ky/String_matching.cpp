#include <bits/stdc++.h>
using namespace std;
// Hàm tính bảng prefix function
vector<int> Check(const string& P) {
    int m = P.length();          // Lấy độ dài của mẫu P
    vector<int> pi(m);           // Khởi tạo vector pi có kích thước bằng độ dài của mẫu P, để lưu trữ bảng prefix function
    int k = 0;                   // Biến k dùng để theo dõi độ dài của tiền tố khớp dài nhất
    pi[0] = 0;                   // Khởi tạo phần tử đầu tiên của bảng prefix function là 0

    // Vòng lặp để tính toán giá trị pi cho từng vị trí trong chuỗi mẫu P
    for (int q = 1; q < m; ++q) {
        // Nếu không có sự khớp, giảm giá trị k về giá trị trước đó của pi
        while (k > 0 && P[k] != P[q]) {
            k = pi[k - 1];
        }
        // Nếu ký tự tại vị trí k và q trong mẫu khớp, tăng giá trị k lên
        if (P[k] == P[q]) {
            ++k;
        }
        pi[q] = k;               // Gán giá trị k cho pi[q]
    }
    return pi;                   
}

// Thuật toán KMP để đếm số lần xuất hiện của P trong T
int KMPSearch(const string& T, const string& P) {
    int n = T.length();         
    int m = P.length();          
    vector<int> pi = Check(P); 
    int q = 0;                   // Biến q theo dõi số ký tự đã khớp
    int count = 0;               // Biến count để đếm số lần xuất hiện của mẫu P trong T

    // Vòng lặp để duyệt qua từng ký tự của văn bản T
    for (int i = 0; i < n; ++i) {
        // Nếu ký tự không khớp, giảm giá trị q về giá trị trước đó trong bảng pi
        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
        }
        // Nếu ký tự tại vị trí q trong mẫu và vị trí i trong văn bản khớp, tăng giá trị q lên
        if (P[q] == T[i]) {
            ++q;
        }
        // Nếu toàn bộ mẫu đã khớp (giá trị q bằng độ dài mẫu)
        if (q == m) {
            ++count;             // Tăng biến đếm count lên
            q = pi[q - 1];       // Đặt lại q về giá trị trước đó trong bảng pi
        }
    }
    return count;             
}

int main() {
    string P, T;               
    cin >> P >> T;               
    int result = KMPSearch(T, P);  
    cout << result << endl;     
    return 0;                    
}
