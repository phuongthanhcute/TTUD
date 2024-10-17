#include <bits/stdc++.h>
using namespace std;

string s, v;
set<string> Q;
int main(){
    cin>>s;
    while(s != "*"){
        Q.insert(s);
        cin>>s;
    }
    cin>>s;
    while(s != "***"){
        cin>>v;
        if(s[0]=='f'){
            if(Q.find(v)!=Q.end()) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else{
            if(Q.find(v)!=Q.end()) cout<<0<<endl;
            else{
                cout<<1<<endl;
                Q.insert(v);
            }
        }
        cin>>s;
    }
}
