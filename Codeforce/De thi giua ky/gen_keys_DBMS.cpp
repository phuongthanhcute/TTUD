// có n khóa độ dài bằng L, cần thêm m khóa độ dài bằng L khác các khóa đã cho
// viết theo thứ tự từ điển
#include <bits/stdc++.h>
using namespace std;
int n, L, m;

string solve(const string &s)//hàm dùng để tăng khóa
{
    string result = s;
    int len = result.length();
    for (int i = len - 1; i >= 0; --i)
    {
        if (result[i] < '9') 
        {
            result[i]++;
            break;
        }
        else
            result[i] = '0';
    }
    return result;
}
int main()
{
    cin >> n >> L >> m;
    set<string> keys; // luwu cac khoa da cho truoc do
    vector<string> res;
    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        keys.insert(key);
        res.push_back(key);
    }

    string currentKey(L, '0');
    currentKey[L - 1] = '1'; // đặt số cuối bằng 1 để tránh chuỗi toàn 0
    while (m > 0)
    {   //check xem khóa sđã tồn tại chưa
        if (keys.find(currentKey) == keys.end())
        {
            keys.insert(currentKey); //nếu chưa thì thêm vào set và thêm vào kết quả
            res.push_back(currentKey);
            --m;
        }
        currentKey = solve(currentKey); //tạo khóa mới bằng hàm tăng khóa ở trên rồi quay lại duyệt tiếp
    }
    sort(res.begin(), res.end());
    for (const string &key : res)
    {
        cout << key << endl;
    }
    return 0;
}