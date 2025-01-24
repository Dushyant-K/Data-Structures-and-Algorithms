class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //Approach-1
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};