#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];
int res =0;
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    int i=1, j=n;
    while(i<j){
        if(a[i]+a[j] == m) res++;
        if(a[i]+a[j]>m) j--;
        else i++;
    }
    cout<<res;
    return 0;
    
}
