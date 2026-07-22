class Solution {
private:
    bool isSafeToPlace(int rowIdx, int colIdx, vector<string>& board){
        int n = board.size();

        // horizontal attack
        int r{rowIdx}, c{colIdx};
        while(c >= 0) if(board[r][c--] == 'Q') return false;

        // left upper diagonal attack
        r = rowIdx; c = colIdx;
        while(r >= 0 && c >= 0) if(board[r--][c--] == 'Q') return false;

        // left lower diagonal
        r = rowIdx; c = colIdx;
        while(r < n && c >= 0) if(board[r++][c--] == 'Q') return false;

        return true;
        
    }
    void solve(int n, int c, vector<string> board, vector<vector<string>>& ans){
        // base case. If col index becomes greater than n, means we have successfully placed all the queens
        if(c >= n){
            vector<string> temp;
            for(int i = 0; i < n; i++){
                temp.push_back(board[i]);
            }
            ans.push_back(temp);
            return;
        }
        for(int i{0}; i < n; i++){
            if(isSafeToPlace(i,c,board)){
                board[i][c] = 'Q';
                solve(n,c+1,board,ans);
                // backtrack so we don't place multiple queens in one column
                board[i][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // Board
        vector<string> board(n,string(n,'.'));
        vector<string> op;
        int colIdx = 0;
        vector<vector<string>> ans;
        solve(n,colIdx,board,ans);
        return ans;
    }
};