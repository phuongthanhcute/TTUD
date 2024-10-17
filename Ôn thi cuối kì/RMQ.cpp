#include <bits/stdc++.h>
using namespace std;
 


long long a[1000001];     //a[N]
long long st[21][1000001]; //st[LG+1][N]: LG=__lg(log2(N))


int queryMin(int l, int r){
    long long  k=floor(log2(r-l+1));
    return st[k][l] < st[k][r- (1<<k) +1] ? st[k][l] : st[k][r-(1<<k)+1];
}

int main(){
    long long N,m,x,y,i,j;
    long long sum=0;
    scanf("%ld", &N);
    long long LG=floor(log2(N));

    for(int i=1;i<=N;++i) scanf("%ld", &a[i]);

    for( i=1;i<=N;++i) st[0][i]=a[i];
    for(j=1;j<=LG;++j){
        for(i=1;i+(1<<j) -1 <=N;++i){
            st[j][i]=st[j-1][i] < st[j-1][i+(1<<(j-1))] ? st[j-1][i] : st[j-1][i+(1<<(j-1))];
        }
    }
    scanf("%ld", &m);
    for(i=1;i<=m;++i){
        scanf("%ld %ld ", &x, &y);
        sum+=queryMin(x+1,y+1);
    }
    printf("%ld",sum);
    return 0;
}  