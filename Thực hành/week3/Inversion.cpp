#include <iostream>
#include <vector>

using namespace std;

// Function to count inversions
long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inversions = 0;

    while (i < mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += mid - i;
        }
    }

    while (i < mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; ++i) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inversions = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> temp(n);
    long long inversions = mergeSort(arr, temp, 0, n - 1);

    cout << inversions % (1000000007LL) << endl;

    return 0;
}
