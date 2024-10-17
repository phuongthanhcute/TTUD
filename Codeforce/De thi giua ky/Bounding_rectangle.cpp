#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int minX = 101, minY = 101, maxX = -1, maxY = -1;
    
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Tìm tọa độ nhỏ nhất và lớn nhất
        minX = min(minX, min(x1, x2));
        minY = min(minY, min(y1, y2));
        maxX = max(maxX, max(x1, x2));
        maxY = max(maxY, max(y1, y2));
    }
    
    // Tính diện tích của hình chữ nhật bao quanh
    int area = (maxX - minX) * (maxY - minY);
    
    // In kết quả
    cout << area << endl;
    
    return 0;
}
