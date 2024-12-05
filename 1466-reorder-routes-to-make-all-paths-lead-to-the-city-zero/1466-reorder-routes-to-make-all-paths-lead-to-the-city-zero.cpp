class Solution {
    private:
    int bfs(int src, vector<int> adj[], vector<int>& visited, vector<int>& reachability){
       queue<int> q;
       q.push(src);
       visited[src]=1;

       int count=0;
       while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(reachability[it]==0){
                    count++;
                    reachability[it]=1;
                }
                visited[it]=1;
                q.push(it);
            }
        }
       }
       return count;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //Approach-1(BFS Algorithim)
        vector<int> adj[n];
        vector<int> visited(n,0);
        vector<int> reachability(n,0);
        reachability[0]=1;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            if(v==0)reachability[u]=1;
        }

        //containers are ready
       queue<int> q;
       int count=0;
       for(int i=0;i<n;i++){
        if(visited[i]==0){
            count+=bfs(i,adj,visited,reachability);
        }
       }
       return count;
    }
};