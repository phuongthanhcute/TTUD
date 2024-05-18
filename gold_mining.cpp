#include <bits/stdc++.h>
using namespace std;
const int MAX=1000002;
int n, L1, L2;
int a[1000002];
int maxW[MAX];
int maxWeights;

int main(){
    cin>>n>>L1>>L2;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        if(i<L1) maxW[i] = a[i];
    }

    deque<int> D; //luu cac nha kho dc xet trong moi buoc
    
    for(int i=1; i<=n; ++i){
        // Khi cac nha kho minh xet nam ngoai doan [L1, L2] 
        // bo cac index nam ben trai [i-L2, i-L1]
        while (!D.empty() && D.front() < i-L2) {
            D.pop_front();
        }

        //Khi nha kho minh xet co tru luong vang nho hon tai i-L1
        //bo di cac index ma maxW tai do <= maxW[i-L1]
        while(!D.empty() && maxW[D.back()] <= maxW[i-L1]) {
            D.pop_back();
        }
        D.push_back(i-L1);
        maxW[i] = maxW[D.front()]+a[i];
        maxWeights = maxWeights < maxW[i] ? maxW[i] : maxWeights;
    }
    cout<< maxWeights;
    return 0;
}
