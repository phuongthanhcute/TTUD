#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000002;
int n;
long long a[MAX];
long long maxEven[MAX];
long long maxOdd[MAX];
long long res=0;
int main(){
    freopen("testcase.txt", "r", stdin);
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    if(a[1]%2==0) maxEven[1]=a[1];
    else maxOdd[1]=a[1];
    int j=2;
    while(j<=n){
        if(a[j]%2==0) {
            maxEven[j]= max(a[j], maxEven[j-1]+a[j]);
            maxOdd[j] =  maxOdd[j-1]+a[j];
        }
        if(a[j]%2!=0){
            maxOdd[j] = max(a[j], maxEven[j-1]+a[j]);
            maxEven[j]  =  maxOdd[j-1]+a[j];
        }
        res = max(res, maxEven[j]);
        j++;
    }
    cout <<res;
    return 0;
}