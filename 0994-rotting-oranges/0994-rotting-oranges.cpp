class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Approach-1
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int t=0;
        int adjRow[] = {0,1,0,-1};
        int adjCol[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            t = max(t,time);
            for(int i=0;i<=3;i++){
                int newRow = row+adjRow[i];
                int newCol = col+adjCol[i];
                if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m&&visited[newRow][newCol]==0&&grid[newRow][newCol]==1){
                    visited[newRow][newCol]=2;
                    q.push({{newRow,newCol},time+1});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]==1)return -1;
            }
        }
        return t;
    }
};