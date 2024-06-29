class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//Appraoach-1
      set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
         
        int index=0;
        for(auto it:st){
        nums[index]=it;
        index++;
        }
        return index;
      
//Approach-2
        // int i=0;
        // for(int j=1;j<nums.size();j++){
        //     if(nums[j]!=nums[i]){
        //         nums[i+1]=nums[j];
        //         i++;
        //     }
        // }
        // return (i+1);
    }
};