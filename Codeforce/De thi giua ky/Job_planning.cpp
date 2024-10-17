#include <bits/stdc++.h>
using namespace std;
// bài toán sắp xếp công việc sao cho hoàn thành trước hạn chót và đạt lợi nhuận lớn nhất
// ý tưởng: Greedy

struct Job
{
    int d; // deadline
    int p; // profit
};

bool compare(Job a, Job b)
{
    return a.p > b.p;
}

int main()
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].d >> jobs[i].p;
    }
    // sắp xếp các công việc theo thứ tự lợi nhuận giảm dần
    sort(jobs.begin(), jobs.end(), compare);
    set<int> available_slots; // lưu trữ các thời gian có săn
    for (int i = 1; i <= 100000; ++i)
    {
        available_slots.insert(i);
    }
    int total_profit = 0;
    for (int i = 0; i < n; ++i)
    {
        // it trỏ vào phần tử tiếp theo trong available_slots mà lớn hơn jobs[i].d
        auto it = available_slots.upper_bound(jobs[i].d);
        if (it != available_slots.begin()) //nếu có slots
        {
            --it;
            total_profit += jobs[i].p;
            available_slots.erase(it);
        }
    }
    cout << total_profit;
    return 0;
}
