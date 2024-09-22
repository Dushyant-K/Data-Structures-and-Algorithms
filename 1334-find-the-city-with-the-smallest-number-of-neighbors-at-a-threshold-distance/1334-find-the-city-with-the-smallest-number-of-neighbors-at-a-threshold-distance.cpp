class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Approach-1(Floyd Warshall Algorithm)
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u][v] = w;
            adj[v][u] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        int minCount=INT_MAX;
        int minReachableCity=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j&&adj[i][j]<=distanceThreshold)count++;
            }
            if(count<=minCount){
                minCount=count;
                minReachableCity=i;
            }
        }
        return minReachableCity;
    }
};