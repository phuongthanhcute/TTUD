#include <bits/stdc++.h>
using namespace std;
/*
int n, k1, k2;
int a[1001][1001] = {}; // a[x][k] = số cách xếp thỏa mãn cho tới ngày k, x={0,1} là trạng thái nghỉ/làm của ngày đó
int main()
{
	cin >> n >> k1 >> k2;
	a[0][0] = a[0][1] = 0;
	a[0][1] = 1;
	for (int i = 1; i < k1 - 1; ++i)
	{
		a[1][i] = 0;
		a[0][i + 1] = a[1][i];
		a[1][k1] = 1;
	}
	for(int i=k1; i<=n; ++i){
		a[0][i]=a[1][i-1];
		
	}
}*/

int total[1005] = {}, n, k1, k2, m = 1e9 + 7;
int main(){
    cin >> n >> k1 >> k2;
    ++k2;
    for(int i = ++k1; i <= k2; ++i)
        total[i] = 1;
    for(int i = k2 + 1; i <= n + 1; ++i)
        for(int j = k1; j <= k2; ++j)
            total[i] = (total[i] + total[i-j]) % m;
    cout << total[n - 1] + 2 * total[n] + total[n + 1];
}