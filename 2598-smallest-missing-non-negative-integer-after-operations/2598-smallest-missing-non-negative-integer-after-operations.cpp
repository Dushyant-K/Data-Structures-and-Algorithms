class Solution {
public:
    bool isPossible(vector<int>& nums, int number, int value){
        unordered_set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                int reduced = nums[i]%value;
                while(st.find(reduced)!=st.end()){
                    reduced+=value;
                }
                if(reduced==number)return true;
                st.insert(reduced);
            }else{
                int absolute = abs(nums[i]);
                int reduced = absolute%value;
                while(reduced<0||st.find(reduced)!=st.end()){
                    reduced+=value;
                }
                if(reduced==number)return true;
                st.insert(reduced);
            }
        }
        return false;
    }
    int findSmallestInteger(vector<int>& nums, int value) {
        //Approach-1(Using Binary Search)
        int n = nums.size();

        int ans = n;

        int low=0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(nums,mid,value)){
                low = mid+1;
            }else{
                ans = mid;
                high=mid-1;
            }
        }

        return ans;
    }
};