#include <bits/stdc++.h>
using namespace std;

int x[31]; //x[k]=v: giao vine v day mon k 
int teach[11][31]={}; //teach[v][k]=1:  nhung hoc phan k ma giao vien v co the day
int conflict[31][31]={}; //xung dot: hoc phan h xung dot hp k khi c[h][k]=c[k][h]=1


int n, m; //n course, m teachers
int tMaxLoad=0;
int load[11] ={1}, maxLoad = 1e9;

bool check(int k, int v){
    for(int i=k+1; i<=n;++i){
        if(x[i] == v && conflict[k][i] == 1) return false;
    }
    return true;
}

void Try(int k){
    for(int v=1; v<=m; ++v){
        if(teach[v][k]==1 && check(k, v)){
            x[k]=v;
            load[v]++;
            int p=0;
            if(load[v]>tMaxLoad) {
                tMaxLoad++;
                p=1;
            }
            if(k==1){
                if(tMaxLoad<maxLoad) maxLoad=tMaxLoad;
            }
            else if (tMaxLoad<maxLoad) Try(k-1);

            load[v]--;
            if(p==1) tMaxLoad--;
        }
    }
}
int main(){
    cin>>m>>n;
    int x,y,z;
    for(int i=1; i<=m; ++i){
        cin>>x;
        while(x>0){
            cin>>y;
            teach[i][y]=1;
            x--;
        }
    }

    cin>>z;
    while(z>0){
        cin>>x>>y;
        conflict[x][y]=conflict[y][x]=1;
        z--;
    }
    Try(n);
    cout<<maxLoad;
    return 0;
}