#include<bits/stdc++.h>
using namespace std;
int n,k,a[25][25];
int stmp=0,smin=999,load=0,cmin=999;
int visited[30];
bool check_point(int x){
    if(visited[x]) return false;
    if(x<=n){
        if (load+1>k) return false;
    } 
    else 
        if(!visited[x-n]) return false;
    return true;
}
void TRY(int k,int pre){
    for(int i=1;i<=2*n;++i){
        if(check_point(i)){
            visited[i]=1;
            stmp+=a[pre][i];
            if(i<=n) ++load;
            else --load;
            if(stmp+cmin*(2*n-k+1)<=smin){
                if(k==2*n){
                    stmp+=a[i][0];
                    smin=stmp<smin?stmp:smin;
                    stmp-=a[i][0];
                } 
                else TRY(k+1,i);
            }
            if(i<=n) --load;
            else ++load;
            visited[i]=0;
            stmp-=a[pre][i];
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<=2*n;++i){
        for(int j=0;j<=2*n;++j){
            scanf("%d",&a[i][j]);
            if(a[i][j]) cmin=a[i][j]<cmin?a[i][j]:cmin;
        }
    }
    TRY(1,0);
    printf("%d",smin);
}
