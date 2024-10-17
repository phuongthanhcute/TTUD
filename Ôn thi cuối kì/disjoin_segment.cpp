#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>> &segments){
    sort(segments.begin(),segments.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    }); //sap xep cac doan theo thu tu diem cuoi tang dan
    int res = 0, end_point = -1;
    for(const auto&segment : segments){
        if(segment.first > end_point){
            res++;
            end_point = segment.second;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> segments(n);
    for(int i=0; i<n; ++i){
        cin>>segments[i].first>>segments[i].second;
    }
    cout<<solve(segments);
    return 0;
}