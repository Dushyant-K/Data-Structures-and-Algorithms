class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //Approach-1(Djikstra's algorithim)
        if(n==0)return (0.0);

        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double probability=succProb[i];

            adj[u].push_back({v,probability});
            adj[v].push_back({u,probability});
        }

        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        vector<double> maxProb(n,0);

        pq.push({1,start_node});
        maxProb[start_node]=1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double prob=it.first;
            int node=it.second;

            for(auto next:adj[node]){
                int neighbour=next.first;
                double nextProb=next.second;
                if(prob*nextProb>maxProb[neighbour]){
                    maxProb[neighbour]=prob*nextProb;
                    pq.push({maxProb[neighbour],neighbour});
                }
            }
        }

        return maxProb[end_node];
    }
};