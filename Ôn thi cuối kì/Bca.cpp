//bca
#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int conflict[50][50], x[50], res = 100, sT[50];
vector<int> teach[50];

bool Kiemtra(int teacher, int subject){
    for(int i=0;i<subject; ++i)
        if(x[i] == teacher)
            if(conflict[i][subject] == 1)
                return false;  
    return true;
}

void Try(int subject){
    if(subject > n){
        res = 0;
        for(int i=0; i<m; ++i){
            res = max(res, sT[i]);
        }
        return;
    }

    for(int i=0; i<teach[subject].size(); ++i){
        int teacher = teach[subject][i];
        if(Kiemtra(teacher, subject)){
            x[subject] = teacher;
            if(++sT[teacher] <= res)
                Try(subject+1);
            --sT[teacher];
        }
    }
}
int main(){
    int i,j;
    cin>>m>>n;;
    for(i=0;i<m;++i){
        cin>>k;
        while(k--){
            cin>>j;
            teach[j].push_back(i); 
        }
    }
    cin >> k;
    while(k--){
        cin>>i>>j;
        conflict[i][j] = 1;
        conflict[j][i] = 1;
    }
    Try(1);
    if(res == 100)
        cout<<-1;
    else 
        cout<<res;
        return 0;
}
