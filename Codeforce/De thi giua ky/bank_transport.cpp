#include <bits/stdc++.h>
using namespace std;
//bài toán chia n túi tiền vào 2 xe sao cho chênh lệch giữa 2 xe là nhỏ nhất
int res = INT_MAX, tong=0;

void Try(vector<int> &val, int index, int sum1, int sum2)
{
    //sum1, sum2: tổng số tiền hiện tại của xe 1 và xe 2
    //val: lưu danh sách lượng tiên ở mỗi túi
    if (index == val.size()) //nếu đã duyệt qua cả n túi
    {
        int difference = abs(sum1 - sum2);
        res = min(res, difference);
        return;
    }
    if(sum1 * 2 > tong){
        res = min(res, 2*sum1-tong);
        return;
    }
    if(sum2 * 2 > tong){
        res = min(res, 2*sum2-tong);
        return;
    }
    
    // Thử thêm túi tiền vào xe 1
    Try(val, index + 1, sum1 + val[index], sum2);
    // Thử thêm túi tiền vào xe 2
    Try(val, index + 1, sum1, sum2 + val[index]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> val(n); // mảng lưu giá trị từng túi tiền
    for (int i = 0; i < n; ++i)
    {
        cin >> val[i];
        tong += val[i];
    }

    Try(val, 0, 0, 0);
    cout << res << endl;
    return 0;
}
