class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        //Approach-1(using Map)
        map<int, int> count;
    for (int fruit : basket1) count[fruit]++;
    for (int fruit : basket2) count[fruit]--;

    vector<int> surplus1, surplus2;
    for (auto& [fruit, diff] : count) {
        if (diff % 2 != 0) return -1;  // Impossible case
        int half = abs(diff) / 2;
        if (diff > 0)
            surplus1.insert(surplus1.end(), half, fruit);
        else
            surplus2.insert(surplus2.end(), half, fruit);
    }

    if (surplus1.empty()) return 0;

    sort(surplus1.begin(), surplus1.end());
    sort(surplus2.rbegin(), surplus2.rend());  // reverse sort

    int globalMin = min(*min_element(basket1.begin(), basket1.end()),
                        *min_element(basket2.begin(), basket2.end()));

    long long totalCost = 0;
    for (size_t i = 0; i < surplus1.size(); ++i) {
        int directSwap = min(surplus1[i], surplus2[i]);
        totalCost += min(directSwap, 2 * globalMin);  // double-swap trick
    }

    return totalCost;
    }
};