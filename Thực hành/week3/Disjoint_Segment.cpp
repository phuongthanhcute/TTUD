#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNonOverlappingIntervals(vector<pair<int, int>>& segments) {
    // Sort segments based on their right endpoints
    sort(segments.begin(), segments.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    int count = 1;  // Initialize count of non-overlapping intervals
    int last_end = segments[0].second;  // Endpoint of the last selected interval
    
    // Iterate through all intervals starting from the second one
    for (int i = 1; i < segments.size(); ++i) {
        // If the left endpoint of the current interval is greater than
        // the endpoint of the last selected interval, increment the count
        // and update the endpoint of the last selected interval
        if (segments[i].first > last_end) {
            count++;
            last_end = segments[i].second;
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    // Output the maximum number of non-overlapping segments
    cout << maxNonOverlappingIntervals(segments) << endl;
    
    return 0;
}
