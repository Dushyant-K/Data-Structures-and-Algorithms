class Solution {
public:
    int countAllPaths(vector<int> nums,int n, int idx, int count){
        if(idx>=(n-1))return count;
        int mini =INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            mini = min(countAllPaths(nums,n,idx+i,count+1),mini);
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int mini = countAllPaths(nums,n,0,0);
        return mini;
    }
};