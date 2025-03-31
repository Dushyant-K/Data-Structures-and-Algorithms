class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Approach-1(Using Set DataStructure)
        int n=nums.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int longest=1;

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                longest=max(cnt,longest);
            }
        }
        return longest;
    }
};