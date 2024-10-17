#include <bits/stdc++.h>
using namespace std;

vector<string> gen_key(int n, int m, const vector<int> &numbers){
    vector<string> keys;
    for(int i: numbers){
        ostringstream oss; //đối tượng stream ở output
        oss << setw(m) <<setfill('0') << i; //định dạng số nguyên i thành chuỗi có độ dài m với các số 0 ở đầu
        keys.push_back(oss.str());// chuyển đổi đầu ra thành định dạng chuỗi và lưu ó vào vector output
    }
    return keys;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> numbers(n); // luu cac input keys
    for(int i=0; i<n ;++i){
        cin>>numbers[i];
    }

    vector<string> keys = gen_key(n, m, numbers); //luu outputkeys
    for(const string& key: keys){
        cout<<key<<endl;
    }
    return 0;
}