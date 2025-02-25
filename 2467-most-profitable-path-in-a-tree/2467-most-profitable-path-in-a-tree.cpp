class Solution {
private:
    bool dfsBob(int currentNode, vector<int> adj[], int time, unordered_map<int,int>& bobTime, vector<int>& visited) {
        visited[currentNode] = true;
        bobTime[currentNode] = time;

        if (currentNode == 0) return true;

        for (auto it : adj[currentNode]) {
            if (!visited[it]) {
                if (dfsBob(it, adj, time + 1, bobTime, visited)) return true;
            }
        }

        bobTime.erase(currentNode);
        return false;
    }

    void dfsAlice(int currentNode, vector<int> adj[], int currProfit, int time, unordered_map<int,int>& aliceTime, vector<int>& visited, vector<int>& amount, int& maxProfit, unordered_map<int,int>& bobTime) {

        visited[currentNode] = true;
        aliceTime[currentNode] = time;

        if (bobTime.find(currentNode) == bobTime.end() || bobTime[currentNode] > time) {
            currProfit += amount[currentNode];
        }
        else if (bobTime[currentNode] == time) {
            currProfit += amount[currentNode] / 2;
        }

        if (adj[currentNode].size() == 1 && currentNode != 0) {
            maxProfit = max(maxProfit, currProfit);
            return;
        }

        for (auto it : adj[currentNode]) {
            if (!visited[it]) {
                dfsAlice(it, adj, currProfit, time + 1, aliceTime, visited, amount, maxProfit, bobTime);
            }
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // Number of nodes
        vector<int> adj[n];

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, int> bobTime;
        vector<int> visited(n, 0);
        dfsBob(bob, adj, 0, bobTime, visited);

        unordered_map<int, int> aliceTime;
        int maxProfit = INT_MIN;
        int currentProfit = 0; // Define this before passing it

        fill(visited.begin(), visited.end(), 0); // Reset visited array before Alice's DFS

        dfsAlice(0, adj, currentProfit, 0, aliceTime, visited, amount, maxProfit, bobTime);

        return maxProfit;
    }
};
