#include <bits/stdc++.h>
using namespace std;

int H, W; //height, width
int n; //number of submaterials

int Size[11][11]; //matrix size of submaterial


int main(){
    cin>>H>>W;
    cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", Size[i][j]);
        }
    }
}