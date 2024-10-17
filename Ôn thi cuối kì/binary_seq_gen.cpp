#include <bits/stdc++.h>
using namespace std;

int n;

void Try(int n, string str, vector<string> &res){
    if(str.length() == n){
        res.push_back(str);
        return;
    }
    Try(n, str+'0', res);
    Try(n, str+'1', res);
}
int main(){
    cin>>n;
    vector<string> res;
    Try(n, "", res);
    for(const string& str : res){
        cout<<str<<endl;
    }
    return 0;
}