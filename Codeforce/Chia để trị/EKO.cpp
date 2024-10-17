#include <bits/stdc++.h>
using namespace std;

unsigned long long res;
const long long maxn= 10e6+7;
unsigned long long N, M; //number of trees
unsigned long long h[maxn];
bool check(unsigned long long m){
    unsigned long long sum = 0;
    for(int i=1; i<=N; ++i){
        if(h[i]>m) sum+=h[i]-m;
    }
    return sum>=M;
}

long long solve(){
    sort(h+1, h+N+1);
    res=0;
    unsigned long long l, r, mid;
    l=0; r=h[N];
    while(l<r-1){
        mid = (l+r)/2;
        if(check(mid)){
            res = mid;
            l = mid;
        }
        else r = mid;
    }
    return res;
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        cin>>h[i];
    }
    cout<<solve();
    return 0;
}