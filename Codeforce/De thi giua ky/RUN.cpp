#include <bits/stdc++.h>
using namespace std;
//CHIA THÀNH BAO NHIÊU DÃY CON TĂNG
int n;
const int maxn=100005;
long long a[maxn];
int main(){
   // freopen("test.txt", "r", stdin);
    int count =0;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    for(int i=n-1; i>=1; --i){
        if(a[i-1]>=a[i]) count++;
    }
    cout<<count+1;
    return 0;
}