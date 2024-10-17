#include <bits/stdc++.h>
using namespace std;

//bài toán tìm chi phí nhỏ nhất đi từ đầu đến đích (né các ô có quái vật)
int n, m;                // n hang, m cot
long long x[1001][1001]; // x[i][j] = chi phí tới ô (i,j)
int near[3][2] = {{-1, 0},
                  {0, -1},   // i là di chuyển theo cột, j là di chuyển theo hàng
                  {-1, -1}}; // near[i][j] để hiện cách di chuyển về ô trước đó
int main()
{
    cin >> n >> m;
    x[0][0] = 1; // chi phí ô đầu tiên = 1
    for (int i = 1; i <= n; ++i)
        x[i][0] = INT_MAX;
    for (int j = 1; j <= m; ++j)
        x[0][j] = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> x[i][j];
            if (x[i][j] == 0)
            {
                x[i][j] = INT_MAX; // nếu không đi tới được thì gán chi phí là vô cực
                continue;
            }
            long long curr = INT_MAX; // chi phí hiện tại
            for (int k = 0; k < 3; ++k)
            {                                                      // backtrack
                long long tmp = x[i + near[k][0]][j + near[k][1]]; // chi phí đi đến ô trước đó
                if (tmp != 1e13) //nếu có thể đi được tới ô trước đó
                {
                    curr = min(curr, tmp + x[i][j]); //cập nhật chi phí hiện tại 
                }
            }
            x[i][j] = curr; //cập nhập chi phí x[i][j] bằng chi phí đi từ đầu tới ô (i,j)
        }
    }
    if (x[n][m] == 1e13)//nếu ô đích có quái vật
        x[n][m] = 0; //không đi tới được
    cout << x[n][m] - 1; //chi phí đi tới đích -1 (trừ chi phí xuất phát)
    return 0;
}