#include<bits/stdc++.h>
using namespace std;
//đếm số cặp bằng nhau trong mảng
int main() {
    map<int, int> m; // Tạo một map để lưu tần suất xuất hiện của mỗi phần tử
    int n, a, cnt = 0; // n: số lượng phần tử trong mảng, a: giá trị của từng phần tử, c: biến đếm số cặp
    cin >> n; // Nhập số lượng phần tử của mảng

    while(n--) { // Vòng lặp để duyệt qua từng phần tử của mảng
        cin >> a; // Nhập giá trị của phần tử hiện tại
        cnt += m[a]++; // Tăng biến đếm số cặp dựa trên tần suất hiện tại của phần tử a trong map
    }

    cout << cnt; // In ra kết quả số cặp phần tử bằng nhau
}
