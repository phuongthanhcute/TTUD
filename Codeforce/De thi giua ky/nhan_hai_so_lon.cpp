#include <bits/stdc++.h>
using namespace std;
//bài toán nhân 2 số lớn
string nhan(string num1, string num2){
    int n1= num1.size();
    int n2 = num2.size();

    vector<int> res(n1+n2, 0);
    for(int i=n1-1; i>=0; --i){
        for(int j=n2-1; j>=0; --j){
            int tich = (num1[i]-'0')*(num2[j]-'0');
            int tong = tich + res[i+j+1];

            res[i+j+1] = tong%10;
            res[i+j] += tong/10;
        }
    }

    string S;
    for(int i: res){
        if(!(S.empty() && i==0)){
            S.push_back(i+'0');
        }
    }
    return S.empty() ? "0": S;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<nhan(a,b);
    return 0;
}