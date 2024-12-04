class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //Approach-1
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //First let me prepare the containers
        vector<long long> time(n,LLONG_MAX),pathCount(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        time[0]=0;
        pathCount[0]=1;
        pq.push({0,0});
        int mod = (1e9+7);
        //Now just applying simple djiskstra Algorithm
        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int neighbour = it.first;
                long long price = it.second;
                if(cost+price<time[neighbour]){
                    time[neighbour]=cost+price;
                    pathCount[neighbour]=pathCount[node];
                    pq.push({time[neighbour],neighbour});
                }
                else if(cost+price==time[neighbour]){
                    pathCount[neighbour]=(pathCount[neighbour]%mod+pathCount[node]%mod)%mod;
                }
            }
        }
        return (pathCount[n-1]);
    }
};