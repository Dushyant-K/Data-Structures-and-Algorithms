class Solution {
    private:
    vector<int> topologicalSort(int n, vector<vector<int>>& adj, vector<int>& indegree) {
        queue<int> q;
        vector<int> result;

        // Add nodes with 0 indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS for topological sorting
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the result size is not equal to the number of nodes, there's a cycle
        return result.size() == n ? result : vector<int>();
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
       // Step 1: Assign unique group IDs to items with group[i] == -1
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        // Step 2: Create adjacency lists and indegree arrays for items and groups
        vector<vector<int>> groupAdj(m), itemAdj(n);
        vector<int> groupIndegree(m, 0), itemIndegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                // Build the item-level graph
                itemAdj[prev].push_back(i);
                itemIndegree[i]++;

                // Build the group-level graph if items belong to different groups
                if (group[prev] != group[i]) {
                    groupAdj[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        // Step 3: Perform topological sort on groups
        vector<int> sortedGroups = topologicalSort(m, groupAdj, groupIndegree);
        if (sortedGroups.empty()) return {}; // Return empty if there's a cycle

        // Step 4: Perform topological sort on items
        vector<int> sortedItems = topologicalSort(n, itemAdj, itemIndegree);
        if (sortedItems.empty()) return {}; // Return empty if there's a cycle

        // Step 5: Group items according to their groups
        unordered_map<int, vector<int>> groupToItems;
        for (int item : sortedItems) {
            groupToItems[group[item]].push_back(item);
        }

        // Step 6: Combine items in the sorted order of groups
        vector<int> result;
        for (int grp : sortedGroups) {
            for (int item : groupToItems[grp]) {
                result.push_back(item);
            }
        }

        return result;
    }
};