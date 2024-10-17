//cap
#include <bits/stdc++.h>
using namespace std;

int T, n, m, cnt = 0;
long long a[105], b[105];
map<int, int> mm;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
            mm[a[i]]++;
        }
        cin>>m;
        for(int i=0;i<m;++i){
            cin>>b[i];
            if(mm.find(b[i]) != mm.end()){
                cnt++;
            }
        }
    }
    cout<<cnt;
}