#include <bits/stdc++.h>
using namespace std;

//bài toán đếm số dãy con có trọng số chẵn
const int mod = 1000000007;
int n;
int a[100005];
int main(){
    cin>>n;
    int res = 0; //số dãy con có tổng chẵn
    int prefixSum = 0; //tổng tiền tố
    int countEven = 1; //Số phần tử chẵn đã duyệt qua, phần tử đầu tiên là 0
    int countOdd = 0; //số phần tử lẻ đã duyệt qua
    for(int i=0; i<n; i++){
        cin>>a[i];
        prefixSum += a[i];
        if(prefixSum %2 ==0 ){
            res += countEven;
            countEven++;
        }
        else{
            res+=countOdd;
            countOdd++;
        }
    }
    cout<<res%mod;
    return 0;
}