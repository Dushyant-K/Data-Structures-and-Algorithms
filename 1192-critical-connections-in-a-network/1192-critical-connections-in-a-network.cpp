class Solution {
    private:
    int timer=1;
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges){
        visited[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent)continue;
            if(visited[it]==0){
                dfs(it,node,adj,visited,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //Approach-1
        vector<int> adj[n];
        for(auto it:connections){
            int node1 = it[0];
            int node2 = it[1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        //Prepare the containers
        vector<int> visited(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        //Now start the iteration
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,-1,adj,visited,tin,low,bridges);
            }
        }
        return bridges;
    }
};