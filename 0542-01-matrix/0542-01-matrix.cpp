class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //Approach-1
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            dist[row][col]=distance;
            for(int i=0;i<4;i++){
                int numRow = row+drow[i];
                int numCol = col+dcol[i];
                if(numRow>=0&&numRow<n&&numCol>=0&&numCol<m&&visited[numRow][numCol]==0){
                    visited[numRow][numCol]=1;
                    q.push({{numRow,numCol},distance+1});
                }
            }
        }
        return dist;
    }
};