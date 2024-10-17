#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int MAX=0;

void dfs(int base){
    if(base<MAX){
        for (int i=0; i<=9; ++i){
            int newNum = base*10+i;
            if(newNum !=0 && newNum<=MAX){
                arr.push_back(newNum);
                dfs(newNum);
            }
        }
    }
}

int main(){
    cin>>n;
    MAX =n;
    dfs(0);
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
    