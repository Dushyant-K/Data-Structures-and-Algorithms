class Solution {
private:
    // void dfs(int src, vector<int> adj[], vector<int>& visited,
    // vector<int>&pathVisited, vector<int> cycle, int& maxi){
    //     visited[src]=1;
    //     pathVisited[src]=1;
    //     cycle.push_back(src);
    //     for(auto it:adj[src]){
    //         if(visited[it]==0){
    //             dfs(it,adj,visited,pathVisited,cycle,maxi);
    //         }
    //         else if(pathVisited[it]==1){
    //             int idx=-1;
    //             int size=cycle.size();
    //             for(int i=0;i<size;i++){
    //                 if(it==cycle[i]){
    //                     idx=i;
    //                     break;
    //                 }
    //             }
    //             maxi=max(maxi,size-idx);
    //         }
    //     }
    //     pathVisited[src]=0;
    //     cycle.pop_back();
    // }
    void dfs(int src, vector<int> adj[], vector<int>& visited,
             vector<int> pathVisited, int& maxi) {
        visited[src] = 1;
        pathVisited[src] = 1;
        for (auto it : adj[src]) {
            if (visited[it] == 0) {
                dfs(it, adj, visited, pathVisited,maxi);
            } else if (pathVisited[it] == 1) {
                int length=1;
                int dummy=adj[it][0];
                while(dummy!=it){
                    dummy=adj[dummy][0];
                    length++;
                }
                maxi = max(maxi,length);
            }
        }
        pathVisited[src] = 0;
    }

public:
    int longestCycle(vector<int>& edges) {
        // Approach-1
        //  int n=edges.size();
        //  vector<int> adj[n];
        //  for(int i=0;i<edges.size();i++){
        //      if(edges[i]!=-1)adj[i].push_back(edges[i]);
        //  }

        // vector<int> visited(n,0), pathVisited(n,0);
        // vector<int> cycle;
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     if(visited[i]==0)dfs(i,adj,visited,pathVisited,cycle,maxi);
        // }
        // if(maxi==INT_MIN)return -1;
        // return maxi;

        // Approach-2(Optimizing the space complexity)
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> visited(n, 0), pathVisited(n, 0);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                dfs(i, adj, visited, pathVisited, maxi);
        }
        if (maxi == INT_MIN)
            return -1;
        return maxi;
    }
};