#include <bits/stdc++.h>
using namespace std;

//baif toasn viet n thanh tong cua k so voi n,k cho truoc
void Try(int k, int n, vector<int> &res, int index, int sum)
{
    //res là vector lưu kết quả, sum là tổng hiện tại, index là số vị trí đã điền hiện tại
    //nếu đã điền đủ k số
    if(index == k){
        if(sum  == n){
            for(int i=0; i<k; ++i){
                cout<<res[i];
                if(i<k-1) cout<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //nếu chưa điền đủ, thử điền i vào vị trí tiếp theo
    for(int i= (index == 0 ? 1:res[index-1]); i<=n; ++i){
        if(sum+i >n)  break;
        res[index] = i; //nếu thỏa mãn lưu i vào vị trí tiếp theo
        Try(k, n, res, index+1, sum+i);
    }

}
int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> res(k);
    Try(k, n, res, 0 , 0);
    return 0;
}