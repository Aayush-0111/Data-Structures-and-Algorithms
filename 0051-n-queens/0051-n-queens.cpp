class Solution {
private:
    void solve(int n, int c, vector<string>& board, vector<vector<string>>& ans, vector<bool>& b1, vector<bool>& b2, vector<bool>& b3){
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
            if(!b1[i] && !b2[i-c+n-1] && !b3[i+c]){
                board[i][c] = 'Q';
                b1[i] = true; // indicates ith row contains queen
                b2[i-c + (n-1)] = true; // indicates left upper diagonal contains queen & (n-1) normalize negatives 
                b3[i+c] = true; // indicates left lower diagonal contains queen
                solve(n,c+1,board,ans,b1,b2,b3);
                // backtrack so we don't place multiple queens in one column
                board[i][c] = '.';
                b1[i] = false;
                b2[i-c + (n-1)] = false;
                b3[i+c] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        // Board
        vector<string> board(n,string(n,'.'));
        vector<bool> b1(n,false),b2(2*n-1,false),b3(2*n-1,false);
        vector<vector<string>> ans;
        solve(n,0,board,ans,b1,b2,b3);
        return ans;
    }
};