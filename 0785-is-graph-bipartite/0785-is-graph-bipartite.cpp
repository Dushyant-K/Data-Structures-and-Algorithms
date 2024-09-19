class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // number of nodes in the graph
        vector<int> color(n, -1); // color array to store color of each node (-1 means uncolored)

        // We need to check each component of the graph (as it might be disconnected)
        for (int i = 0; i < n; i++) {
            // If the node is not yet colored, we use BFS to try coloring the component
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0; // Start coloring the first node with color 0
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    // Try to color all adjacent nodes with the opposite color
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == -1) {
                            // If neighbor is not colored, color it with the opposite color
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // If neighbor has the same color as the current node, it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};