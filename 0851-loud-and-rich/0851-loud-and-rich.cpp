class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        //Approach-1(Topology Sort)
        int n = quiet.size();
        if (n == 0) return {};

        // Build adjacency list and in-degree array
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto &it : richer) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // Initialize ans: everyone is initially their own quietest person
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }

        // Topological sorting using BFS
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &neighbor : adj[node]) {
                // Update quietest person for the neighbor
                if (quiet[ans[node]] < quiet[ans[neighbor]]) {
                    ans[neighbor] = ans[node];
                }

                // Decrease in-degree and add to queue if it becomes 0
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};