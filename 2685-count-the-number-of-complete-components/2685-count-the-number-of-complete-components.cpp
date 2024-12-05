class Solution {
    private:
    void dfs(int src, vector<int> adj[], vector<int>& visited, stack<int>& st){
        visited[src]=1;
        st.push(src);
        for(auto it:adj[src]){
            if(visited[it]==0){
                dfs(it,adj,visited,st);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //Approach-1(DFS Algorithim)
        vector<int> adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            stack<int> st;
            if(visited[i]==0){
                dfs(i,adj,visited,st);
                int size=st.size();
                bool flag=true;
                while(!st.empty()){
                    int node=st.top();
                    st.pop();
                    if(adj[node].size()!=size-1){
                        flag=false;
                        break;
                    }
                }
                if(flag)components++;
            }
        }
        return components;
    }
};