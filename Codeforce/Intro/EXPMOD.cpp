#include <iostream>
using namespace std;

const long long MOD = 1000000007;
unsigned long long a,b;
int main(){
    cin>>a>>b;
    unsigned long long x=1, y = a%MOD;
    while(b>0){
        if(b&1) x = (x*y)%MOD;
        y = (y*y)%MOD;
        b = b>>1;
    }
    cout<<x%MOD;
}
