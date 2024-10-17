#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int a;
    queue<int> S;
    cin >> str;
    while (str != "#")
    {
        if (str[1] == 'U')
        {
            cin >> a;
            S.push(a);
        }
        if (str[1] == 'O')
        {
            if (!S.empty())
            {
                int top = S.front();
                cout<<top<<endl;
                S.pop();
            }
            else{
                cout<<"NULL"<<endl;
            }
        }
        cin >> str;
    }
}