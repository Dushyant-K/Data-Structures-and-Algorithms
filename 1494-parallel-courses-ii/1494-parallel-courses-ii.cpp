class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        //Approach-1(Topology Sorting)
               vector<int> adj[n + 1], indegree(n + 1, 0);
        
        // Build adjacency list and indegree array
        for (auto it : relations) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        // Add all nodes with indegree 0 (no prerequisites)
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int semester = 0;
        while (!q.empty()) {
            int size = q.size();
            semester++;  // Increment semester count for the current batch of courses
            
            // Only process up to k courses in this semester
            int coursesToProcess = min(size, k);
            for (int i = 0; i < coursesToProcess; i++) {
                int course = q.front();
                q.pop();
                
                // Reduce the indegree of child nodes
                for (auto next : adj[course]) {
                    indegree[next]--;
                    if (indegree[next] == 0) q.push(next); // Add new nodes with indegree 0
                }
            }
        }

        return semester;
    }
};