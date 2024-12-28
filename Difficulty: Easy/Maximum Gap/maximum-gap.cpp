//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int maxSortedAdjacentDiff(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;  // If less than 2 elements, return 0

    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());

    if (maxVal == minVal) return 0;

    int bucketSize = std::max(1, (maxVal - minVal) / (n - 1));
    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    std::vector<int> minBucket(bucketCount, std::numeric_limits<int>::max());
    std::vector<int> maxBucket(bucketCount, std::numeric_limits<int>::min());

    for (int num : arr) {
        int idx = (num - minVal) / bucketSize;
        minBucket[idx] = std::min(minBucket[idx], num);
        maxBucket[idx] = std::max(maxBucket[idx], num);
    }

    int maxGap = 0, prevMax = minVal;

    for (int i = 0; i < bucketCount; ++i) {
        if (minBucket[i] == std::numeric_limits<int>::max()) continue;
        maxGap = std::max(maxGap, minBucket[i] - prevMax);
        prevMax = maxBucket[i];
    }

    return maxGap;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxSortedAdjacentDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends