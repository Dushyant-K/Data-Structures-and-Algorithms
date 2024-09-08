class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans.push_back(-1);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=(i+n-1);j++){
                int index = j%n;
                if(nums[i]<nums[index]){
                    ans[i]=nums[index];
                    break;
                }
            }
        }
        return ans;
    }
};