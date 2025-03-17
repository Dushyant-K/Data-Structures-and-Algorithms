class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //Approach-1
        int n=nums.size();
        unordered_set<int> st;
        for(auto it:nums){
            if(st.count(it)==1)st.erase(it);
            else st.insert(it);
        }

        return st.empty();
    }
};