class Solution {
public:
    int countHillValley(vector<int>& nums) {
        //Approach-1(Using precomputed left and right arrays)
        int n = nums.size();

        vector<int> left(n,0);
        vector<int> right(n,0);

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])left[i]=nums[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]!=nums[i+1])right[i]=nums[i+1];
        }

        int count=0;

        int counter=1;
        while(nums[counter]==nums[counter-1])counter++;
        if(counter>=n-1)return 0;

        for(int i=counter;i<=n-2;i++){
            int leftElement = left[i];
            while(i<n-1&&nums[i]==nums[i+1])i++;
            if(i!=n-1){
                int rightElement = right[i];
                if((nums[i]>leftElement&&nums[i]>rightElement)||(nums[i]<leftElement&&nums[i]<rightElement))count++;
            }
        }

        return count;
    }
};