class Solution {
    private:
    void findAllPerm(vector<int>& nums, unordered_set<int> st, vector<int> temp, vector<vector<int>>& ans, int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(st.find(i)!=st.end())continue;
            temp.push_back(nums[i]);
            st.insert(i);
            findAllPerm(nums,st,temp,ans,n);
            st.erase(i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //Approach-1
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        unordered_set<int> st;
        findAllPerm(nums,st,temp,ans,n);
        return ans;
    }
};