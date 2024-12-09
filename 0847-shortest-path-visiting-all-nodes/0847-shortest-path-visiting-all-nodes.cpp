class Solution {
    struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine the two hash values
    }
};
public:
    int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 1) return 0;

    // The final state where all nodes are visited
    int finalState = (1 << n) - 1;

    // Queue for BFS: (currentNode, visitedMask, currentDistance)
    queue<tuple<int, int, int>> q;

    // To keep track of visited states: (currentNode, visitedMask)
    unordered_set<pair<int, int>, pair_hash> visited;

    // Initialize the queue with all nodes as starting points
    for (int i = 0; i < n; i++) {
        int initialMask = (1 << i);
        q.emplace(i, initialMask, 0);
        visited.insert({i, initialMask});
    }

    // Perform BFS
    while (!q.empty()) {
        auto [node, visitedMask, dist] = q.front();
        q.pop();

        // If all nodes are visited, return the current distance
        if (visitedMask == finalState) return dist;

        // Traverse all neighbors
        for (int neighbor : graph[node]) {
            int nextMask = visitedMask | (1 << neighbor);
            if (!visited.count({neighbor, nextMask})) {
                q.emplace(neighbor, nextMask, dist + 1);
                visited.insert({neighbor, nextMask});
            }
        }
    }

    return -1; // Should not reach here if the graph is connected
    }
};