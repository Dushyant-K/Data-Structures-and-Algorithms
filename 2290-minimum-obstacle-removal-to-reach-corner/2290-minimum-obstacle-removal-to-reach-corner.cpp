class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        //Approach-1
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        visited[0][0]=1;
        int adjRow[]={-1,0,1,0};
        int adjCol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int distance=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1&&col==m-1)return distance;

            for(int i=0;i<4;i++){
                int nextRow=row+adjRow[i];
                int nextCol=col+adjCol[i];
                if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&visited[nextRow][nextCol]==0){
                    visited[nextRow][nextCol]=1;
                    if(grid[nextRow][nextCol]==1)pq.push({distance+1,{nextRow,nextCol}});
                    else pq.push({distance,{nextRow,nextCol}});
                }
            }
        }
        return -1;
    }
};