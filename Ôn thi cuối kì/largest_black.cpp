#include <bits/stdc++.h>
using namespace std;
 //largest black subrectagle
//khong dung stack, chi dung mang
int n, m, a[1005][1005], mark[1005];

int solve(){
    int res = 0;
    int left[1005], right[1005];
    left[0] =-1;
    for(int i=1; i<m; ++i){
        int p=i-1;
        if(mark[p]>=mark[i] && p>0){
            p = left[p];
        }
        left[i] = p;
    }

    right[m-1] = m;
    for(int i=m-2;i>=0; --i){
        int p=i+1;
        if(mark[p]>=mark[i] && p<=m-1){
            p = right[p];
        }
        right[i] = p;
    }

    for(int i=0; i<m; ++i){
        res = max(res, (right[i]-left[i]-1)*mark[i]);
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            if(a[i][j]) mark[j]++;
        }
    }
    cout<<solve();
    return 0;
}