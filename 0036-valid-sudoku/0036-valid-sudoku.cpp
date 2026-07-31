class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            int j = 0;
            int frq[10] = {0};
            while(j < 9){
                if(board[i][j] == '.') {
                    ++j;
                    continue;
                }
                int x = board[i][j] - '0';
                if(frq[x]) return false;
                frq[x] = 1;
                ++j;
            }
            j = 0;
            memset(frq,0,sizeof(frq));
            while(j < 9){
                if(board[j][i] == '.') {
                    ++j;
                    continue;
                }
                int x = board[j][i] - '0';
                if(frq[x]) return false;
                frq[x] = 1;
                ++j;
            }
        }
        // check 3x3 boards
        for(int i = 0; i < 9; i+=3){
            int frq[10] = {0};
            for(int r = i; r < i+3; r++){
                for(int c = 0; c < 3; c++){
                    if(board[r][c] == '.') continue;
                    int x = board[r][c] - '0';
                    if(frq[x]) return false;
                    frq[x] = 1;
                }
            }
            memset(frq,0,sizeof(frq));
            for(int r = i; r < i+3; r++){
                for(int c = 3; c < 6; c++){
                    if(board[r][c] == '.') continue;
                    int x = board[r][c] - '0';
                    if(frq[x]) return false;
                    frq[x] = 1;
                }
            }
            memset(frq,0,sizeof(frq));
            for(int r = i; r < i+3; r++){
                for(int c = 6; c < 9; c++){
                    if(board[r][c] == '.') continue;
                    int x = board[r][c] - '0';
                    if(frq[x]) return false;
                    frq[x] = 1;
                }
            }
        }
        return true;
    }
};