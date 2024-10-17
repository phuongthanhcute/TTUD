//tìm dãy con có trọng số lớn nhất
#include <bits/stdc++.h>
using namespace std;

//quy hoạch động
int qhd(const vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 0); //luu trong so cua day con ket thuctai i
    dp[0] = arr[0];
    for(int i=1; i<n; ++i){
        dp[i] = max(dp[i],dp[i-1] + arr[i]);
    }
    int res = dp[0];
    for(int i=1; i<n; ++i){
        res = max(res, dp[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    cout<<qhd(a);
    return 0;
}