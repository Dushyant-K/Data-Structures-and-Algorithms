class Solution {
    private:
    bool dfs(int node, vector<int> adj[], vector<vector<int>>& dp, vector<int>& color, vector<int>& visited, vector<int>& recursionStack, int& result) {
        if (visited[node] == 1) return false; // Cycle detected
        if (visited[node] == 2) return true;  // Already processed
        
        visited[node] = 1; // Mark as visiting
        recursionStack[node] = 1; // Add to recursion stack
        
        for (int neighbor : adj[node]) {
            if (recursionStack[neighbor] || !dfs(neighbor, adj, dp, color, visited, recursionStack, result)) {
                return false; // Cycle detected
            }
            // Update dp[node] with max frequencies from neighbors
            for (int c = 0; c < 26; c++) {
                dp[node][c] = max(dp[node][c], dp[neighbor][c]);
            }
        }
        
        recursionStack[node] = 0; // Remove from recursion stack
        dp[node][color[node]]++; // Include current node's color
        result = max(result, dp[node][color[node]]);
        visited[node] = 2; // Mark as fully processed
        return true;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //Approach-1(topological Sorting)
                int n = colors.size();
        vector<int> adj[n];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // Initialize data structures
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            color[i] = colors[i] - 'a'; // Map colors to integers
        }
        vector<vector<int>> dp(n, vector<int>(26, 0)); // DP table for color frequencies
        vector<int> visited(n, 0); // Track visit status of nodes
        vector<int> recursionStack(n, 0); // Track current recursion stack
        int result = 0;
        
        // Perform DFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!dfs(i, adj, dp, color, visited, recursionStack, result)) {
                    return -1; // Cycle detected
                }
            }
        }
        
        return result;
    }
};