class Solution {
public:
    int solve(int idx, vector<int>& points){
        if(idx<=0)return 0;


        //Take
        int take=points[idx]+solve(idx-2,points);

        //Not-Take
        int not_take=solve(idx-1,points);

        return max(take,not_take);
    }
    int deleteAndEarn(vector<int>& nums) {
       //Approach-1(Recursion backtracking)
       int n=nums.size();
       int maxi=*max_element(nums.begin(),nums.end());

       vector<int> points(maxi+1,0);

       for(auto it:nums){
        points[it]+=it;
       } 

       return solve(maxi,points);
    }
};