#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first; // trả lại phần tử có chi phí lớn hơn
    }
};
int main()
{
    int n, m, tmp1, tmp2;
    scanf("%d %d", &n, &m);
    int C[n + 1], D[n + 1];
    vector<vector<int>> v(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &C[i], &D[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        v[tmp1].push_back(tmp2);
    }

    // tìm đường đi ngắn nhất
    // Hàng đơi ưu tiên lưu chi phí cho tới hiện tại và cặp {i, d[i]}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
    pq.push({0, {1, 0}}); // đỉnh 1, chi phí hiện tại =0, d[1]=0
    while (!pq.empty())
    {
        int curr_res = pq.top().first; // loại bỏ đỉnh đầu tiên ra khỏi hàng đợi
        pair<int, int> u = pq.top().second;
        pq.pop();
        if (u.first == n)// nếu duyệt hết n đỉnh
        {                           
            printf("%d", curr_res); // in ra chi phí cần tìm
            break;
        }
        for (auto v : v[u.first])
        { // xét mỗi đỉnh v kề với đỉnh hiện tại
            
            if (u.second > 0)
                // nếu d[u]>0 thì thêm đỉnh v vào hàng đợi, giảm d[u] đi 1 (tức là vẫn có thể duyệt tiếp)
                pq.push({curr_res, {v, u.second - 1}});
            // cập nhật chi phí hiện tại thêm C[u.first], thêm đỉnh v vào hàng đợi, số đỉnh có thể duyệt tiếp là d[u]-1
            pq.push({curr_res + C[u.first], {v, D[u.first] - 1}});
        }
    }
}