#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define HNT ios_base::sync_with_stdio(false); cin.tie(0);
typedef long long ll;

const int MAX = 505;
ll M, K;                // Số lượng cuốn sách và số phần cần chia
ll Page[MAX];           // Số lượng trang sách của mỗi cuốn

// Kiểm tra xem có thể chia sách thành K phần với tổng lớn nhất mỗi phần là maxPages hay không
bool canDivide(ll maxPages) {
    int parts = 1;
    ll currentSum = 0;

    for (int i = 0; i < M; i++) {
        if (currentSum + Page[i] > maxPages) {
            parts++;
            currentSum = Page[i];
            if (parts > K) {
                return false;
            }
        } else {
            currentSum += Page[i];
        }
    }

    return true;
}

// Tìm chỉ số để chia sách thành các phần với tổng lớn nhất mỗi phần là maxPages
void findSplitIndexes(ll maxPages, vector<int>& splitIndexes) {
    int parts = 1;
    ll currentSum = 0;
    splitIndexes.clear();

    for (int i = M - 1; i >= 0; i--) {
        if (currentSum + Page[i] > maxPages || i + 1 < K - parts + 1) {
            splitIndexes.push_back(i + 1);
            parts++;
            currentSum = Page[i];
        } else {
            currentSum += Page[i];
        }
    }
    reverse(splitIndexes.begin(), splitIndexes.end());
}

int main() {
    HNT;
    int test;
    cin >> test;

    while (test--) {
        cin >> M >> K;
        ll sumPages = 0;
        ll maxPage = 0;

        for (int i = 0; i < M; i++) {
            cin >> Page[i];
            sumPages += Page[i];
            maxPage = max(maxPage, Page[i]);
        }

        ll left = maxPage, right = sumPages, mid;

        // Tìm kiếm nhị phân để tìm giá trị tối ưu của mid
        while (left < right) {
            mid = (left + right) / 2;
            if (canDivide(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        vector<int> splitIndexes;
        findSplitIndexes(left, splitIndexes);

        // In ra kết quả
        int lastIndex = 0;
        for (int i = 0; i < splitIndexes.size(); i++) {
            for (int j = lastIndex; j < splitIndexes[i]; j++) {
                cout << Page[j] << " ";
            }
            if (i < splitIndexes.size() - 1) {
                cout << "/ ";
            }
            lastIndex = splitIndexes[i];
        }

        // In phần cuối cùng
        for (int i = lastIndex; i < M; i++) {
            cout << Page[i];
            if (i != M - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
