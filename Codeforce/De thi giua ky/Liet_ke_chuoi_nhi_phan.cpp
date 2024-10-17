//Bài toán liệt kê chuỗi nhị phân không chứa "11"
#include <bits/stdc++.h>
using namespace std;

int n;
bool check(const string &Str){
    for(int i=1; i<Str.length(); i++){
        if(Str[i]=='1' && Str[i-1]=='1') return false;
    }
    return true;
}

void Try(int n, string curr, vector<string> &res){
    if(curr.length() == n) {
        if(check(curr)) res.push_back(curr);
        return;
    }
    Try(n, curr+'0', res);
    Try(n, curr+'1', res);
}

int main(){
    cin>>n;
    vector<string> res;
    Try(n, "", res);
    for(const string &Str: res){
        cout<<Str<<endl;
    }    
    return 0;
}