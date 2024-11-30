class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //Approach-1
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;
        
        // Build the graph and calculate in-degree and out-degree
        for (auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }
        
        // Find the start node for the Eulerian path
        int start = pairs[0][0]; // Default start
        for (auto& [node, out] : outDegree) {
            if (out > inDegree[node]) {
                start = node;
                break;
            }
        }
        
        // Perform Hierholzer's algorithm to find the Eulerian path
        vector<int> path;
        stack<int> stack;
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stack.push(next);
            } else {
                path.push_back(node);
                stack.pop();
            }
        }

        reverse(path.begin(), path.end());
        
        // Convert the Eulerian path to the required pair format
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};