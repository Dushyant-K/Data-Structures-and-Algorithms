class Solution {
    private:
    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int& changes) {
    visited[node] = true;
    for (const auto& [neighbor, needsReorder] : graph[node]) {
        if (!visited[neighbor]) {
            changes += needsReorder; // Count if this edge needs reordering
            dfs(neighbor, graph, visited, changes);
        }
    }
}

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //Approach-1(BFS Algorithim)
       // Build adjacency list for the graph
    vector<vector<pair<int, int>>> graph(n);
    
    for (const auto& conn : connections) {
        graph[conn[0]].emplace_back(conn[1], 1); // Original edge (needs reordering)
        graph[conn[1]].emplace_back(conn[0], 0); // Reverse edge (does not need reordering)
    }
    
    int changes = 0;
    vector<bool> visited(n, false);
    
    // Call the DFS starting from city 0
    dfs(0, graph, visited, changes);
    return changes;
    }
};