class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //Approach-1(BFS Algorithim)
         vector<pair<int, int>> adj[n]; 
        
        for (auto& edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0}); 
        }
   
        for (auto& edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1}); 
        }

        vector<int> dist(n, INT_MAX); 
        vector<vector<bool>> visited(n, vector<bool>(2, false)); 

        queue<pair<int, pair<int, int>>> q;

        dist[0] = 0;
        q.push({0, {0, -1}}); 

        while (!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second.first;
            int color = q.front().second.second;
            q.pop();

            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int nextColor = neighbor.second;
                if (nextColor == color || visited[nextNode][nextColor]) continue;

                dist[nextNode] = min(dist[nextNode], distance + 1);
                visited[nextNode][nextColor] = true;
                q.push({nextNode, {distance + 1, nextColor}});
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==1e8)dist[i]=-1;
        }
        return dist;
    }
};