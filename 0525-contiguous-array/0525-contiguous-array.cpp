class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //Approach-1(Using prefix Sum)
        int n = nums.size();

        unordered_map<int,int> mpp;
        int currSum=0;
        int maxLength=0;
        mpp[0]=-1;

        for(int i=0;i<n;i++){
            currSum+=(nums[i]==1)?1:-1;
            if(mpp.find(currSum)!=mpp.end()){
                maxLength=max(maxLength,(i-mpp[currSum]));
            }else{
                mpp[currSum]=i;
            }
        }

        return maxLength;
    }
};