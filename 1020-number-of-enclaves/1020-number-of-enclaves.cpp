class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //Approach-1
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&(i==0||i==n-1||j==0||j==m-1)){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int numsRow = row+drow[i];
                int numsCol = col +dcol[i];
                if(numsRow>=0&&numsRow<n&&numsCol>=0&&numsCol<m&&grid[numsRow][numsCol]==1&&visited[numsRow][numsCol]==0){
                    visited[numsRow][numsCol]=1;
                    q.push({numsRow,numsCol});
                }
            }
        }

        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};