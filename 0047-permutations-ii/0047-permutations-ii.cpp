class Solution {
public:
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, set<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.insert(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            continue;
        }
        
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<bool> used(nums.size(), false);
    vector<int> current;
    set<vector<int>> result;
    
    backtrack(nums, used, current, result);
    
    return vector<vector<int>>(result.begin(), result.end());
    }
};