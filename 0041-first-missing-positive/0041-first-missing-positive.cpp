class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Approach
        int n=nums.size();
        unordered_set<int> st;
        int missing=1;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            if(missing==nums[i]){
                missing++;
                while(st.find(missing)!=st.end()){
                    missing++;
                }
            }
        }
        return missing;
    }
};