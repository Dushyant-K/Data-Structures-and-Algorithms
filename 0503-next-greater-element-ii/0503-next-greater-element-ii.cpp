class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Approach-1
        // vector<int> ans;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     ans.push_back(-1);
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<=(i+n-1);j++){
        //         int index = j%n;
        //         if(nums[i]<nums[index]){
        //             ans[i]=nums[index];
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //Approach-2
        int n = nums.size();
        stack<int> st;
        int ans[n];
        for(int i=2*n-1;i>=0;i--){
            if(i>=n){
                while(!(st.empty())&&(nums[i%n]>st.top())){
                    st.pop();
                }
                st.push(nums[i%n]);
            }
            else{
                while(!(st.empty())&&(nums[i]>=st.top())){
                    st.pop();
                }
                if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
             st.push(nums[i]);
            }
        }
        vector<int> nge;
        for(int i=0;i<n;i++){
            nge.push_back(ans[i]);
        }
        return nge;
    }
};