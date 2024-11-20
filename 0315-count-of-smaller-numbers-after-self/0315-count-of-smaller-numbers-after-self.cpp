// Fenwick Tree implementation
class FenwickTree {
private:
    vector<int> tree;
    int maxVal;

public:
    FenwickTree(int size) : tree(size + 1, 0), maxVal(size) {}

    void update(int index, int value) {
        while (index <= maxVal) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }
};
class Solution {
    public:
    vector<int> countSmaller(vector<int>& nums) {
    //Approach-1(Fenwick tree)
    int n = nums.size();
    vector<int> sortedNums(nums);
    vector<int> result(n, 0);

    // Sort the array and map each number to a rank
    sort(sortedNums.begin(), sortedNums.end());
    for (int& num : nums) {
        num = lower_bound(sortedNums.begin(), sortedNums.end(), num) - sortedNums.begin() + 1;
    }

    FenwickTree fenwickTree(n);
    for (int i = n - 1; i >= 0; --i) {
        result[i] = fenwickTree.query(nums[i] - 1); // Count smaller elements
        fenwickTree.update(nums[i], 1);           // Update Fenwick Tree
    }

    return result;
    }
};