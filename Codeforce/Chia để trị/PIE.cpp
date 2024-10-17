#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
double V[10005]; //the tich cua mieng banh thu i

int n, f;
int num_test;
double res;
double l,r, mid;
bool check(double val){
    int sum = 0; //so nguoi co the chia
    for(int i=1; i<=n; ++i){
        sum+= floor(V[i]/val);
    }
    return sum >= f+1;
}

void solve(){
    cin>>num_test;
    for(int i=1; i<=num_test; ++i){
        cin>>n>>f;
        for(int j=1; j<=n; ++j){
            double r;
            cin>>r;
            V[j] = PI*r*r;
        }
        sort(V+1, V+n+1);
        //binary search
        l=0;
        r=V[n];
        while(r-l>1e-6){
            mid = (l+r)/2;
            if(check(mid)){
                res = mid;
                l = mid;
            }
            else r = mid;
        }
    printf("%.6lf\n", res);
    }
}
int main(){
    solve();
    return 0;
}
