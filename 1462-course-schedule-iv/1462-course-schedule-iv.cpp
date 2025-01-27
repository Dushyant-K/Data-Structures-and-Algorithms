class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //Approach-1(Floyd Warshall Algorithim)
        vector<vector<bool>> adj(numCourses,vector<bool>(numCourses,false));

       for(auto it:prerequisites){
        int u=it[0];
        int v=it[1];
        adj[u][v]=true;
       }

       int n=queries.size();
       if(n==0)return {};

       for(int i=0;i<numCourses;i++){
        for(int j=0;j<numCourses;j++){
            for(int k=0;k<numCourses;k++){
                adj[j][k]=(adj[j][k]||(adj[j][i]&&adj[i][k]));
            }
        }
       }
       
       vector<bool> ans(n);
       for(int i=0;i<n;i++){
        int u=queries[i][0];
        int v=queries[i][1];
        ans[i]=adj[u][v];
       }

       return ans;
    }
};