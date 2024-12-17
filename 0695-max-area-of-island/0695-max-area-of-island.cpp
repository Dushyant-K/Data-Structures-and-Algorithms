class Solution {
    private:
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        visited[i][j]=1;

        int n=grid.size();
        int m=grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;

        int count=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            count++;
            int row=it.first;
            int col=it.second;

            for(int i=0;i<4;i++){
            int nextRow=row+drow[i];
            int nextCol=col+dcol[i];
            if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&grid[nextRow][nextCol]==1&&visited[nextRow][nextCol]==0){
                visited[nextRow][nextCol]=1;
                q.push({nextRow,nextCol});
            }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(!n||!m)return 0;

        vector<vector<int>> visited(n,vector<int>(m,0));
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    maxi=max(maxi,bfs(i,j,grid,visited));
                }
            }
        }
        return maxi;
    }
};