class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Approach-1(stl-library)
        next_permutation(nums.begin(),nums.end());
    }
};