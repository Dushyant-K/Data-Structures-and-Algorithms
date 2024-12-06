class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        //Approach-1(BFS Algo)
        if (x == y) return 0;

        int max_limit = max(x, y) + 11; 
        vector<int> visited(max_limit, 0);
        queue<int> q;

        q.push(x);
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                if (node == y) return moves;
                if (node < 0 || node >= max_limit || visited[node]) continue;

                visited[node] = 1;
                if (node > 0 && node % 11 == 0) q.push(node / 11);
                if (node > 0 && node % 5 == 0) q.push(node / 5);
                q.push(node + 1);
                q.push(node - 1);
            }
            moves++;
        }
        return -1; 
    }
};