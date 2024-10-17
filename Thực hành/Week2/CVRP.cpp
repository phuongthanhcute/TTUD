#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,K,K1,Q,totalD=0;
//x[i]: the next place of i
//y[j]: the starting place of the j_th vehicle (y[1]<y[2]<...<y[K])
int d[13],x[13],y[13],load[13],visited[13];
//nbRoutes ~ number of trucks have been used  
int segment,nbRoutes;
int c[13][13];
int dist=0,min_dist=999,cmin=999;
//check if vehicle k_th can visit v 
bool checkX(int v, int k){
    if(v > 0 && visited[v]) return false;
    if(load[k] + d[v]>Q) return false;
    return true;
}
//find the next place of s for the k_th vehicle
void TRY_X(int s,int k){
    for(int v=0;v<=n;++v){
        if(checkX(v,k)){
            load[k]+=d[v];
            visited[v]=1;
            ++segment;
            dist+=c[s][v];
            if(dist+cmin*(n+nbRoutes-segment)<=min_dist){
                if(v>0) TRY_X(v,k);
                else {
                    if(k==K){
                        if(segment==n+nbRoutes) min_dist=dist<min_dist?dist:min_dist;
                    } else TRY_X(y[k+1],k+1);
                }
            }
            --segment;
            load[k]-=d[v];
            dist-=c[s][v];
            visited[v]=0;
        }
    }
}
int checkY(int v, int k){
    if(!v) return 0;
    if(load[k]+d[v]>Q) return 0;
    return !visited[v];
}
void TRY_Y(int k){
    for(int v=y[k-1]+1;v<=n;++v){
        if(checkY(v,k)){
            y[k]=v;
            ++segment;
            visited[v]=1;
            dist+=c[0][v];
            load[k]+=d[v];
            if(k==K){
                nbRoutes=segment;
                TRY_X(y[1],1);
            } else TRY_Y(k+1);
            --segment;
            visited[v]=0;
            dist-=c[0][v];
            load[k]-=d[v];
        }
    }
}
int main(){
    
    scanf("%d%d%d",&n,&K1,&Q);
    for(int i=1;i<=n;++i){
        scanf("%d",&d[i]);
        totalD+=d[i];
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            scanf("%d",&c[i][j]);
            if(c[i][j]) cmin=c[i][j]<cmin?c[i][j]:cmin;
        }
    }
    int a=ceil((double)totalD/Q);
    if(a==K1) {
        K=K1;
        TRY_Y(1);
    }
    else{
        for(K=a;K<=K1;++K){
            TRY_Y(1);
            for(int i=0;i<=n;++i){
                d[i]=0;
                y[i]=0;
                load[i]=0;
                visited[i]=0;
                segment=0;
            }
            dist=0;nbRoutes=0;
        }
    }
    printf("%d",min_dist);
    return 0;
}