class Solution {
    private:
    int solve(int row, int col, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});

        int n=grid.size();
        int m=grid[0].size();

        int totalFish=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            totalFish+=grid[row][col];
            grid[row][col]=0;

            for(int i=0;i<4;i++){
                int nextRow=row+drow[i];
                int nextCol=col+dcol[i];

                if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&grid[nextRow][nextCol]>0){
                    q.push({nextRow,nextCol});
                }
            }
        }
        return totalFish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        //Approach-1(BFS)
        int n=grid.size();
        int m=grid[0].size();

        int maxFish=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    maxFish=max(maxFish,solve(i,j,grid));
                }
            }
        }

        return maxFish;
    }
};