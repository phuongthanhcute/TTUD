#include <bits/stdc++.h>
using namespace std;
// đếm số bộ 3 có 1 số bằng tổng 2 số còn lại
int main(){
    int n, a[2005];
    int cnt=0;
    cin>>n;
    unordered_map<int,int> m; //đếm số lần a[i] xuất hiện trong mảng
    for(int i=0; i<n; ++i){
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int sum = a[i] + a[j];
            if(m.find(sum) != m.end()){
                cnt += m[sum];
            }
        }
    }
    cout<<cnt;
    return 0;
}