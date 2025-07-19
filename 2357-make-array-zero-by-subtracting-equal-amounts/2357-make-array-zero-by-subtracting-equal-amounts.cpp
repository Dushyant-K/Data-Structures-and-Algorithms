class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //Approach-1(Using  Unordered Set)
        int n = nums.size();

        unordered_set<int> st;

        for(auto it:nums){
            if(it!=0)st.insert(it);
        }

        return st.size();
    }
};