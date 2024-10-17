#include <bits/stdc++.h>
using namespace std;

//bài toán đếm số phần tử của giao 2 tập hợp
int main(){
    int T,n,m;
    cin>>T;
    long long a[101], b[101];
    for(int t=0; t<T; ++t){
        unordered_map<long long, long long> map;
        int cnt = 0;
        cin>>n;
        for(int i=0; i<n; ++i){
            cin>>a[i];
            map[a[i]]++;
        }
        cin>>m;
        for(int j=0; j<m; ++j){
            cin>>b[j];
            if(map.find(b[j]) != map.end()) cnt++;
        }
        cout<<cnt;
    }
    return 0;

}