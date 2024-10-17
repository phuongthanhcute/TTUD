#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int n, c[MAX][MAX];
bool visited[MAX];
int x[MAX]; //x[a] la vi tri ma tham lan thu a
int Cmin = 0;
int passengers = 0;
int distMin = 2147483647;
int distcurr = 0;

int findMin(){
    int cMin=2147483647;
    for(int i=0;i<=2*n; ++i){
        for(int j=0;j<2*n; ++j){
            if(c[i][j]!=0) Cmin =  Cmin < c[i][j] ? Cmin : c[i][j];
        }
    }
    return Cmin;
}

bool check(int a, int i){
    if(passengers==1)
        if(i<=n) return false;
    if(i>n)
        if(!visited[i-n]) return false;
    if(c[x[a-1]][i]==0) return false;
    if(!visited[i]) return true;
    return false;
}

void Try(int a){
    for(int i=1; i<=2*n; ++i){
        if(check(a,i)){
            x[a]=i;
            visited[i] = true;
            distcurr += c[x[a-1]][i];
            if(i>n)
                passengers--;
            else passengers++;

            if(a==2*n){
                int dist = distcurr+ c[x[2*n]][0];
                distMin = min(distMin, dist);
            }
            else
                if(distcurr +Cmin*(2*n-a)<distMin) Try(a+1);
            visited[i] = false;
            distcurr -= c[x[a-1]][i];
            if(i>n) passengers++;
            else passengers--;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<=2*n;++i){
        for(int j=0;j<=2*n;++j){
            cin>>c[i][j];
        }
    }
    x[0]=0;
    Cmin = findMin();
    Try(1);
    cout<<distMin;
    return 0;
}

//toi uu hon
/*
#include <iostream>
#include <limits.h>

using namespace std;

int a[23][23], b[12];
bool c[12];

void f(int &s, int &min, int x, int n) {
	int i = 0, j, k;
	if (x == n) {
		if (a[b[x-1]][i] < INT_MAX) {
			if (s + a[b[x-1]+n-1][i] < min) 
				min = s + a[b[x-1]+n-1][i];
		}
	}else {
		for (i = 1; i < n; i++) {
			if (i != b[x - 1] && c[i]) {
				b[x] = i;
				c[i] = false;
				if (b[x-1] != 0) s += a[b[x - 1]+n-1][i] + a[i][i+n-1];
				else s = s + a[0][i] + a[i][i+n-1];
				if (s < min) f(s, min, x + 1, n);
				if (b[x-1] != 0) s = s - a[b[x - 1]+n-1][i] - a[i][i+n-1];
				else s = s - a[0][i] - a[i][i+n-1];
				c[i] = true;
			}
		}
	}
	
}

main() {
	int n, m, i, j, x, y, z, s = 0, min = INT_MAX;
	
	cin >> n ;
	
	for (i = 0; i < n+1; i++) {
		c[i] = true;
	}
	for (i = 0; i < 2*n+1; i++) {
		for (j = 0; j < 2*n+1; j++)
			cin >> a[i][j];
	}
	
	c[0] = false;
	b[0] = 0;
	f(s, min, 1, n+1);
	
	cout << min;
}
*/