class Solution {
    private:
    bool checkDesc(int start, vector<int>& nums, int k){
        for(int i=start;i>start-k;i--){
            if(nums[i]>nums[i-1])return false;
        }
        return true;
    }

    bool checkAsc(int start, vector<int>& nums, int k){
        for(int i=start;i<start+k;i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
      //Approach-1(Brute force-Approach)
      int n=nums.size();
      int start=k;
      int end=n-k-1;
      if(start>end)return {};

      vector<int> ans;
      for(int i=start;i<=end;i++){
        if(checkDesc(i,nums,k)&&checkAsc(i,nums,k)){
            ans.push_back(i);
        }
      }  
      return ans;
    }
};