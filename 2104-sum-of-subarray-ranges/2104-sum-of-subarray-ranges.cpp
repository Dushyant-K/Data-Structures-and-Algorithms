class Solution {
public:
    vector<int> getPSE(vector<int>& nums, int n){
        stack<int> st;
        vector<int> pse;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pse.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return pse;
    }

    vector<int> getNSE(vector<int>& nums, int n){
        stack<int> st;
        vector<int> nse;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >=nums[i]) st.pop();
            nse.push_back(st.empty() ? n : st.top());
            st.push(i);
        }
        reverse(nse.begin(), nse.end());
        return nse;
    }

    vector<int> getPGE(vector<int>& nums, int n){
        stack<int> st;
        vector<int> pge;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge.push_back(st.empty() ? -1 : st.top());
            st.push(i);
        }
        return pge;
    }

    vector<int> getNGE(vector<int>& nums, int n){
        stack<int> st;
        vector<int> nge;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <=nums[i]) st.pop();
            nge.push_back(st.empty() ? n : st.top());
            st.push(i);
        }
        reverse(nge.begin(), nge.end());
        return nge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse = getPSE(nums,n);
        vector<int> nse = getNSE(nums,n);
        vector<int> pge = getPGE(nums,n);
        vector<int> nge = getNGE(nums,n);

        long long maxi = 0, mini = 0;
        for(int i=0;i<n;i++){
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            mini += leftMin * rightMin * 1LL * nums[i];

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            maxi += leftMax * rightMax * 1LL * nums[i];
        }
        return maxi - mini;
    }
};
