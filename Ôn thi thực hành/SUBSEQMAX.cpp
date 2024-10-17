#include <bits/stdc++.h>
using namespace std;

//tim day con co trong so nho nhat
long long algorithm(int *a, int n){
    long long *s = new long long[n];
    s[0]=a[0];
    long long max=s[0];
    for(int i=1;i<n;++i){
        if(s[i-1]>0) s[i]=s[i-1]+a[i];
        else s[i]=a[i];
        max= max > s[i] ? max : s[i];
    }
    delete[] s;
    return max;
}

int main(){
    int n;
    int *a;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    printf("%d", algorithm(a, n));
}