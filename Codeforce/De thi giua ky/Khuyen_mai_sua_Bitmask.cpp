#include <iostream>
#include <vector>
using namespace std;
 
//bài toán đếm số tập con của 1 tập hợp có tổng >S cho trước
int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    int threshold;
    cin >> threshold;
    int count = 0;
    // Sử dụng bit masking để liệt kê tất cả các tập con
    // biến mask:chỉ số phần tử của tập con đang xét, số phần tử đó nằm từ 1 tới n-1
    for (int mask = 1; mask < (1 << n); mask++)
    { // bắt đầu từ 1 để tránh tập rỗng
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i)) // xét xem bit thứ i của tập con đó có được chọn hay không
            {
                sum += numbers[i];
            }
        }
        if (sum >= threshold)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
