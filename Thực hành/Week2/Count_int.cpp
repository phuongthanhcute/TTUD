#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int res=0;

void countSolution(int target, int start, int end, int sum){
    if(start==end){
        if(sum==target) res++;
        return;
    }

    int i=1;
    while(sum + a[start]*i <= target){
        countSolution(target, start+1, end, sum+a[start]*i);
        i++;
    }
}

int main(){
    int n,M;
    int tmp;
    cin>>n>>M;
    while(n--){
        cin>>tmp;
        a.push_back(tmp);
    }
    countSolution(M, 0, a.size(), 0);
    printf("%d", res);
}