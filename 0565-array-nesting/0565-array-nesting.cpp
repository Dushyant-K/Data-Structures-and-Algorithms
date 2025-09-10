class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        //Approach-1(Brute Force Approach)
        // int n = nums.size();
        // unordered_map<int,int> idx;
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     idx[i]=nums[i];
        // }

        // for(int i=0;i<n;i++){
        //     unordered_set<int> st;
        //     int k=i;
        //     while(st.find(idx[k])==st.end()){
        //         st.insert(idx[k]);
        //         k=idx[k];
        //     }
        //     ans = max(ans,(int)st.size());
        //     if(ans==n)break;
        // }

        // return ans;

        //Approach-2(Optimal Approach)
        int n = nums.size();
        int maxLength = 0;
      
        for(int i = 0; i<n; i++) {
            int start  = nums[i];
            nums[i] = -1;
            int length = 0;
            
            //Go to depth as much as you can until you hit -1 (i.e. a number which was already visited)
            while(start != -1) {
                length++;
                int temp = start;
                start = nums[start];
                nums[temp] = -1;
            }
          
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};