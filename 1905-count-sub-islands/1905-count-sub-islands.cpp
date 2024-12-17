class Solution {

    private:
    bool bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited){
        visited[i][j]=1;
        int n=grid1.size();
        int m=grid1[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;

            for(int i=0;i<4;i++){
                int nextRow=row+drow[i];
                int nextCol=col+dcol[i];

                if(nextRow>=0&&nextRow<n&&nextCol>=0&&nextCol<m&&visited[nextRow][nextCol]==0&&grid2[nextRow][nextCol]==1){
                    if(grid1[nextRow][nextCol]==1){
                        visited[nextRow][nextCol]=1;
                        q.push({nextRow,nextCol});
                    }
                    else return 0;
                }
            }
        }
        return 1;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //Approach-1(BFS Algorithim)
        int n=grid1.size();
        int m=grid1[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid1[i][j]==1&&grid2[i][j]==1){
                    count+=bfs(i,j,grid1,grid2,visited);
                }
            }
        }

        return count;
    }
};