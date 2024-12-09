class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findParent(parent[n]); // Path compression
    }

    void unionByRank(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (rootX == rootY) return;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootY] > rank[rootX]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        DisjointSet ds(n);

        // Check all pairs (i, j) and connect them if lcm(nums[i], nums[j]) <= threshold
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate LCM of nums[i] and nums[j]
                long long lcm = (1LL * nums[i] * nums[j]) / gcd(nums[i], nums[j]);
                if (lcm <= threshold) {
                    ds.unionByRank(i, j);
                }
            }
        }

        // Count unique components by finding unique parents
        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(ds.findParent(i));
        }

        return components.size();
    }
};