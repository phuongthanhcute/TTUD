#include <bits/stdc++.h>
using namespace std;
// bài toans tìm dãy con tăng dài nhất thỏa mãn điều kiện nó là dãy đẹp
//  Quy hoạch động
vector<long long> qhd(const vector<long long> &arr){
    int n = arr.size();
    vector<int> dp(n, 1);    // lưu độ dài dãy con tăng dài nhất kết thúc tại i
    vector<int> prev(n, -1); // lưu chỉ số phần tử đứng trước nó trong dãy con tăng dài nhất

    for (int i = 1; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (arr[i] == arr[j] + 1 && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    int maxlength = 0, end = 0;
    for (int i = 0; i < n; ++i){
        if (dp[i] > maxlength){
            maxlength = dp[i];
            end = i;
        }
    }
    vector<long long> res;
    while (end != -1)    {
        res.push_back(arr[end]);
        end = prev[end];
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)    {
        int n;
        cin >> n;
        vector<long long> a(n); // Khởi tạo mảng a với kích thước n
        for (int i = 0; i < n; ++i)        {
            cin >> a[i];
        }
        vector<long long> res = qhd(a);
        cout << res.size() << endl;
    }
    return 0;
}
