#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
int n, l1, l2, a[maxn], maxW[maxn], res;
int main(){
    cin>>n>>l1>>l2;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        if(i<l1) maxW[i] = a[i];
    }

    deque<int> D;
    for(int i=1; i<=n; ++i){
        while(!D.empty() && D.front() < i-l2){
            D.pop_front();
        }
        while(!D.empty() && maxW[D.back()] < maxW[i-l1]){
            D.pop_back();
        }
        D.push_back(i-l1);
        maxW[i] = maxW[D.front()]+a[i];
        res = max(res, maxW[i]);
    }
    cout<<res;
}