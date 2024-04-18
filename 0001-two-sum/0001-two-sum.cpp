class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_indices;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_indices.find(complement) != num_indices.end()) {
            result.push_back(num_indices[complement]);
            result.push_back(i);
            return result;
        }
        num_indices[nums[i]] = i;
    }

    return result;
    }
};