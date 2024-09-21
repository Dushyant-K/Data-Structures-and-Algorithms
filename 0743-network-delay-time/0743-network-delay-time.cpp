class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Approach-1
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> minTime(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        minTime[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            for(auto next:adj[node]){
                int adjNode = next.first;
                int nextTime = next.second;
                if(time+nextTime<minTime[adjNode]){
                    minTime[adjNode]=time+nextTime;
                    pq.push({time+nextTime,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(minTime[i]==1e9)return -1;
            ans = max(ans,minTime[i]);
        }
        return ans;
    }
};