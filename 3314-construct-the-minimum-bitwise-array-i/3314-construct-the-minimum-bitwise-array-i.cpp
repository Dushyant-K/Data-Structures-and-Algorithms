class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        //Approach-1(Brute Force Approach)
        int n = nums.size();

        vector<int> ans;

        for(int i=0;i<n;i++){
            bool found = false;
            for(int x=0;x<nums[i];x++){
                if((x|x+1)==nums[i]){
                    found=true;
                    ans.push_back(x);
                    break;
                }
            }
            if(!found)ans.push_back(-1);
        }

        return ans;
    }
};