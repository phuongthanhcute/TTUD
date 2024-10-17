//quy hoach dong
#include <bits/stdc++.h>    
using namespace std;

int n,k;
long long a[1000005];
double maxxxxxx=0.0;

void Init(){
    cin>>n>>k;
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
}

double average(int i, int j){
    int sum = 0;
    for(int id=i; id<=j;++id){
        sum+=a[id];
    }
    return (double)sum/(j-i+1);
}

double solve(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            double tmp = average(i,j);
            if((tmp>maxxxxxx) && (j-i+1)>=k) maxxxxxx = tmp;
        }
    }
    return maxxxxxx;
}
int main(){
    Init();
    printf("%.5lf", solve());
}