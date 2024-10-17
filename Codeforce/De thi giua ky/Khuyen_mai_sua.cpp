#include <bits/stdc++.h>
using namespace std;

int n; 
int a[25];
int year; 

int countSubsets(int *arr, int n, int S) {
    
    int sum = accumulate(arr, arr + n, 0);
    //dp[i][j]: số cách chọn i phần tử có tổng bằng j
    vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = sum; j >= arr[i - 1]; --j) {
            for(int k = n; k > 0; --k) {
                dp[k][j] += dp[k - 1][j - arr[i - 1]];
            }
        }
    }
    
    long long cnt = 0;
    for(int j = S; j <= sum; ++j) {
        for(int i = 1; i <= n; ++i) {
            cnt += dp[i][j];
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> year;
    cout << countSubsets(a, n, year) << endl;
}
