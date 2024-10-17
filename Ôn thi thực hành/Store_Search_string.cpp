#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    set<string> S;
    cin>>a;
    while(a!="*"){
        S.insert(a);
        cin>>a;
    }
    cin>>a; 
    while (a!="***"){
        cin>>b;
        if(a[0]=='f'){
            if(S.find(b)!=S.end()) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else{ 
            if(S.find(b)!=S.end()) cout<<"0"<<endl;
            else {
                cout<<"1"<<endl;
                S.insert(b);
            }
        }
        cin>>a;
    } 
}