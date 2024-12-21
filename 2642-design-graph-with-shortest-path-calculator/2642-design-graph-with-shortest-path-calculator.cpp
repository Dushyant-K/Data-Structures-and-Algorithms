class Graph {
    int n;
    vector<vector<int>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u][v] = cost;
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }

        // Run Floyd-Warshall to initialize shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][k] < 1e9 && adj[k][j] < 1e9) { // Avoid overflow
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
    int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        // Update adjacency matrix if the new edge provides a shorter path
        if (adj[u][v] > cost) {
            adj[u][v] = cost;

            // Recompute shortest paths affected by this edge
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][u] < 1e9 && adj[v][j] < 1e9) { // Avoid overflow
                        adj[i][j] = min(adj[i][j], adj[i][u] + adj[v][j]+cost);
                    }
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        if (adj[node1][node2] == 1e9) return -1;
        return adj[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */