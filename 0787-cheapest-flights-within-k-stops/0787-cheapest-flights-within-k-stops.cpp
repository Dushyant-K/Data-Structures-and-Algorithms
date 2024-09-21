class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Approach-1
        vector<pair<int,int>> adj[n];
       for(auto it:flights) {
          adj[it[0]].push_back({it[1], it[2]});
          }
        vector<int> price(n,1e9);
        price[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k)continue;

            for(auto next:adj[node]){
                int adjNode = next.first;
                int edjWeight = next.second;
                if(cost+edjWeight<price[adjNode] && stops<=k){
                    price[adjNode] = cost+edjWeight;
                    q.push({stops+1,{adjNode,cost+edjWeight}});
                }
            }
        }
        if(price[dst]==1e9)return -1;
        return price[dst];
    }
};