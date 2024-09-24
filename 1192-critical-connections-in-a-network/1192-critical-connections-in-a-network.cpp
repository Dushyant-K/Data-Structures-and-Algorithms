class Solution {
    int timer=1;
    void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], vector<int>& time,          vector<int>& low, vector<vector<int>>& criticalConnections){
        visited[node]=1;
        time[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(visited[it]==0){
                dfs(it,node,visited,adj,time,low,criticalConnections);
                low[node]=min(low[node],low[it]);
                if(low[it]>time[node]){
                    criticalConnections.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[it],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       //Use dfs algorithm
       vector<int> adj[n];
       for(auto it:connections){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<int> visited(n,0);
       vector<int> time(n,0);
       vector<int> low(n,0);
       vector<vector<int>> critcalConnections;
       for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i,-1,visited,adj,time,low,critcalConnections);
        }
       }
       return critcalConnections;
    }
};