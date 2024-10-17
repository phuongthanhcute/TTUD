#include <bits/stdc++.h>
using namespace std;

int n;
int res[20], t[20];
void Try(int k){
    if(k==n){
        for(int i=0; i<n; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=n; ++i){
        if(t[i]==0){
            t[i] = 1;
            res[k] = i;
            Try(k+1);
            t[i] = 0;
        }
    }
}
int main(){
    cin>>n;
    Try(0);
    return 0;
}