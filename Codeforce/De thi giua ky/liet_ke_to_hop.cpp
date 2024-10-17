#include <bits/stdc++.h>
using namespace std;

int n, k, res =0;
int Try(int n, int k, int start, vector<int> &result)
{
    if (result.size() == k)
    { res++;
        /*for (int i = 0; i < k; ++i)
        {
            cout << result[i] << " ";
        }
        cout<<endl;
        return;
        */
    }
    for(int i=start; i <= n; ++i){
        result.push_back(i);
        Try(n, k, i+1, result);
        result.pop_back();
    }
    return res;
}
int main()
{
    cin >> k >> n;
    vector<int> result;
    cout<<Try(n, k, 1, result);
    return 0;
}