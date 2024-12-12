class Solution {
    private:
    bool check(int src,vector<int> adj[], vector<int>& color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else{
                    if(color[it]==color[node])return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //Approach-1(Check for bipartite graph)
        if(n==0)return true;
        vector<int> adj[n+1];
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!check(i,adj,color))return false;
            }
        }
        return true;
    }
};