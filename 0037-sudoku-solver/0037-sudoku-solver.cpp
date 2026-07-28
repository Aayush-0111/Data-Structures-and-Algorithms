class Solution {
private:
    bool isSafeToPlace(vector<vector<char>>& board, int row, int col, char val){
        // check if row already contains same value
        for(int i = 0; i < 9; i++) if(board[row][i] == val) return false;
        // check if column already contains same value
        for(int i = 0; i < 9; i++) if(board[i][col] == val) return false;
        // check if 3x3 box already contains same value
        int ridx = row - row%3;
        int cidx = col - col%3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i+ridx][j+cidx] == val) return false;
            }
        }
        return true;
    }
    bool isEmpty(vector<vector<char>>& board, int *empty){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    empty[0] = i;
                    empty[1] = j;
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int empty[2] = {0};
        if(isEmpty(board,empty)) return true;
        int r = empty[0], c = empty[1];
        for(int i = 1; i <= 9; i++){
            char val = i + '0';
            if(isSafeToPlace(board,r,c,val)){
                board[r][c] = val;
                if(solve(board)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};