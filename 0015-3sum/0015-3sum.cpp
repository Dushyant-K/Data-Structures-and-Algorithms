class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        //Approach-1
        // set<vector<int>> st;
        // for(int i=0;i<n;i++){
        //     set<int> hashset;
        //     for(int k=i+1;k<n;k++){
        //         int third = -(nums[i]+nums[k]);
        //         if(hashset.find(third)!=hashset.end()){
        //             vector<int> temp={nums[i],nums[k],third};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[k]);
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto it:st){
        //     ans.push_back(it);
        // }
        // return ans;

        //Approach-2
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
    }
};