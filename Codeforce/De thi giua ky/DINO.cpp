#include <bits/stdc++.h>
using namespace std;

//bài khủng long đi ở hành lang và vào chuồng
int n;
int p[100005];
string str;
int main(){
    freopen("test.txt", "r", stdin);
    stack<int> S;
    queue<int> Q;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>p[i];
    }
    for(int i=n-1; i>=0; --i){
        S.push(p[i]);
    }
    cin>>str;
    for(int i=0; i<=str.length(); ++i){
        if(str[i]=='C'){
            if(!S.empty()){
                Q.push(S.top());
                S.pop();
            }
        }
        if(str[i]=='H'){
            if(!Q.empty()){
                S.push(Q.front());
                Q.pop();
            }
        }
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}