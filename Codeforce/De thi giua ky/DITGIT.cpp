#include <bits/stdc++.h>
using namespace std;
//bài toán tìm số cách điền các chữ số vào HUST+SOICT = N với N cho trước
// backtracking
int x[8]; // so chu cai khac nhau
int N, T; // so test case
int res;

bool check(int v, int k) // check xem co the dien gia tri v vao x[k] khong
{
    for (int i = 1; i < k; ++i){
        if (x[i] == v) // check trung nhau
            return false;
    }
    return true;
}
void Try(int k){
    for (int v = 0; v < 10; ++v)    {
        if (v == 0)        {
            if (k == 1 || k == 3)
                continue;
        }
        if (check(v, k))        {
            x[k] = v;
            if (k == 7)            {
                if ((1000 * x[1] + 100 * x[2] + 10 * x[3] + x[4] + 10000 * x[3] + 1000 * x[5] + 100 * x[6] + 10 * x[7] + x[4]) == N)                {
                    res++;
                }
            }
            else Try(k+1);
        }
    }
}
int main(){
    cin >> T;
    while (T--)    {   
        res=0;
        cin >> N;
        Try(1);
        cout<<res<<endl;
    }
    return 0;
}