class Solution {
    private:
    bool isValid(int row, int col, int n, int m){
        if(row>=0&&row<n&&col>=0&&col<m)return true;
        return false;
    }
    bool solve(int idx, int row, int col, vector<vector<char>>& board, int n, int m, string word){
        if(idx>=word.size())return true;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nextRow=row+drow[i];
            int nextCol=col+dcol[i];
            if(isValid(nextRow,nextCol,n,m)&&board[nextRow][nextCol]==word[idx]){
                board[nextRow][nextCol]='.';
                if(solve(idx+1,nextRow,nextCol,board,n,m,word))return true;
                board[nextRow][nextCol]=word[idx];
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
       //Approach-1(Recursion)
       int n=board.size();
       int m=board[0].size();

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                board[i][j]='.';
                if(solve(1,i,j,board,n,m,word))return true;
                board[i][j]=word[0];
            }
        }
       } 
       return false;
    }
};