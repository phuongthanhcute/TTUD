#include <bits/stdc++.h>
using namespace std;

//xay dung cau truc 1 canh
struct Edge{
    int u,v,w;
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {};
};

//cau truc cay
typedef struct DisjointSet{
    vector<int> par;
    //ham tao n rung cat gom 1 cay ban dau
    void init(int n){
        par.resize(n+1, 0);
        for(int i=1;i<=n;i++) par[i]=i;
    }
    //ham tim goc cua rung chua cay u
    int find(int u){
        if(par[u]==u) return u;
        return par[u]=find(par[u]);
    }
    //ktra xem cay u va v co chung rung khong, neu khong thi hop nhat 2 rung
    bool join(int u, int v){
        u=find(u);
        v=find(v);
        if(u==v) return false;
        par[v]=u;
        return true;
    }
} DJS;

int main(){
    int N, M, weight=0, hihi=0;//hihi de dam bao rang khong chon thua nhung canh trong cac buoc lap cua thuat toan
    vector<Edge> E;
    cin>>N>>M;
    while(M--){
        int u,v,w;
        cin>>u>>v>>w;
        E.push_back({u,v,w});
    }
    DJS x;
    x.init(N);
    //sap xep lai cac canh theo trong so tang dan
    sort(E.begin(), E.end(), [](Edge &u, Edge &v){
        return u.w<v.w;
    });

    for(auto e: E){
        if(hihi==N) break;
        //neu khong hop nhat duoc thi bo qua
        if(!x.join(e.u, e.v)) continue;
        weight+=e.w; //neu hop nhat duoc, ta them trong so canh vao ket qua
        hihi++;
    }
    printf("%d", weight);
}


