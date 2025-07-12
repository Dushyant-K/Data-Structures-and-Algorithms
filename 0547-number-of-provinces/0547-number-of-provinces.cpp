class Solution {
    private:
    void dfsTraversal(int node, vector<int> adj[], vector<int>& visited){
        visited[node]=1;

        for(auto it: adj[node]){
            if(!visited[it]){
                dfsTraversal(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Approach-1(Using DFS Algorithim)
        int n = isConnected.size();
        vector<int> adj[n+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n+1,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfsTraversal(i,adj,visited);
                provinces++;
            }
        }
        return provinces;
    }
};