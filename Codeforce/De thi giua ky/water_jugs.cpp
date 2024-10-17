#include <bits/stdc++.h>
using namespace std;

struct State{
    int x,y,steps;
    State(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps){}
};

int gcd(int a, int b){
    while(b!= 0){
        int tmp= b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int Solve(int a, int b, int c){
    if(c>max(a,b) || c % gcd(a,b) != 0) return -1;
    queue<State> q;
    set<pair<int, int>> visited;
    q.push(State(0,0,0));
    visited.insert({0,0});

    while(!q.empty()){
        State curr = q.front();
        q.pop();
        //neeus co c lit nuoc trong binh a hoac binh b
        if(curr.x == c || curr.y == c) return curr.steps;
        //đổ nc từ a sang b
        if(curr.x > 0 ){
            if(curr.y <b){
                int pour = min(curr.x, b- curr.y);
            }
        }
    }
}
int main(){

}