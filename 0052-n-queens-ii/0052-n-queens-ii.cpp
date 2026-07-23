class Solution {
private:
    void solve(int n, int c, vector<string>& board, vector<bool>& b1, vector<bool>& b2, vector<bool>& b3, int& ans){
        if(c >= n){
            ans++;
            return;
        }
        for(int r{0}; r < n; r++){
            if(!b1[r] && !b2[r-c+(n-1)] && !b3[r+c]){
                board[r][c] = 'Q';
                b1[r] = true;
                b2[r-c+(n-1)] = true;
                b3[r+c] = true;
                solve(n,c+1,board,b1,b2,b3,ans);
                board[r][c] = '.';
                b1[r] = false;
                b2[r-c+(n-1)] = false;
                b3[r+c] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n,string(n,'.'));
        vector<bool> b1(n,false), b2(2*n-1,false), b3(2*n-1,false);
        solve(n,0,board,b1,b2,b3,ans);
        return ans;
    }
};