class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        //Approach-1(Brute Force Approach)
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int sum = 0;
            int count=0;
            for(int dig = 1;dig*dig<=nums[i];dig++){
                if(nums[i]%dig==0){
                    if(dig==nums[i]/dig){
                        count++;
                        sum+=dig;
                    }else{
                        count+=2;
                        sum+=dig+nums[i]/dig;
                    }
                }
            }
            if(count==4)ans+=sum;
        }

        return ans;
    }
};