#include <bits/stdc++.h>
using namespace std;

int n, k, res  = 1e9, load =0, path = 0, Cmin=1e9;
int c[25][25]; //khoang cach
vector<bool> visited;
vector<int> route; //vi tri hien tai
//vector<int> routepath; //duong di

bool check(int v){
    //not consider point that was visted
    if(visited[v]) return false;
    //neu tra o v ma chua don
    if(v>n){
        if(!visited[v-n]) return false;
    }
    //check weight
    else {
        if(load +1 > k) return false;
    }
    return  true;
}

void solve(int i){
    for(int v=1; v<=2*n; ++v){
        if(check(v)){
            //routepath.push_back(v);
            //print_path();
            route[i] = v;
            path += c[route[i-1]][route[i]];
            visited[v] = true;

            if(v<=n) load++;
            else load--;
            if(i==2*n){
                if(path+c[route[2*n]][0]<res) res = path+c[route[2*n]][0];
            }
            else{
                if(path + Cmin*(2*n-i)<res){
                    solve(i+1);                
                    }
            }

            //restore data structure
            if(v<=n) --load;
            else ++load;
            path-=c[route[i-1]][route[i]];
            visited[v] = false; 

            //routepath.pop_back();
        }
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<=2*n;++i){
        for(int j=0; j<=2*n;++j){
            scanf("%d %d", &c[i][j]);
            if(c[i][j]) Cmin=c[i][j]< Cmin?c[i][j]: Cmin;
        }
    }
    solve(1);
    printf("%d", res);
}