//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // Approach-1
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        distance[source.first][source.second]=0;
        pq.push({0,{source.first,source.second}});
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int numRow = row+drow[i];
                int numCol = col+dcol[i];
                if(numRow>=0&&numRow<n&&numCol>=0&&numCol<m&&grid[numRow][numCol]==1){
                    if(dis+1<distance[numRow][numCol]){
                        distance[numRow][numCol]=dis+1;
                        pq.push({dis+1,{numRow,numCol}});
                    }
                }
            }
        }
        if(distance[destination.first][destination.second]==1e9)return -1;
        return(distance[destination.first][destination.second]);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends