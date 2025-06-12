class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Approach-1(Brute Force Approach)
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it: mpp){
            int element = it.first;
            int freq = it.second;
            pq.push({freq,element});
        }

        vector<int> ans;
        int count=0;
        while(count!=k){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            count++;
        }

        return ans;
    }
};