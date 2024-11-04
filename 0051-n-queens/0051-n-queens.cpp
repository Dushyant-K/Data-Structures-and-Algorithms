class Solution {
private:
bool isPossible(int col, int row, int n, vector<string> board){
    int duprow = row;
    int dupcol = col;

    //Check for upper diagonal
    while(duprow>=0&&dupcol>=0){
        if(board[dupcol][duprow]=='Q')return false;
        duprow--;
        dupcol--;
    }

    duprow=row;
    dupcol=col;
    //Checking for row
    while(dupcol>=0){
        if(board[dupcol][duprow]=='Q')return false;
        dupcol--;
    }

    dupcol=col;
    duprow=row;
    while(duprow<n&&dupcol>=0){
        if(board[dupcol][duprow]=='Q'){
            return false;
        }
        dupcol--;
        duprow++;
    }
    return true;
}
void solve(int col, int n, vector<string> board, vector<vector<string>>& ans){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int i=0;i<n;i++){
        if(isPossible(col,i,n,board)){
            board[col][i]='Q';
            solve(col+1,n,board,ans);
            board[col][i]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        //Approach-1
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,board,ans);
        return ans;
    }
};