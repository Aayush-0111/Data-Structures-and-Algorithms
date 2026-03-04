class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    // check row
                    int x = 0;
                    bool flag = true;
                    while(x < m){
                        if(mat[i][x] == 1 && x != j) {
                            flag = false;
                            break;
                        }
                        x++;
                    }
                    if(!flag) break;
                    // check column
                    int y = 0;
                    while(y < n){
                        if(mat[y][j] == 1 && y != i){
                            flag = false;
                            break;
                        }
                        y++;
                    }
                    if(!flag) break;
                    count++;
                }
            }
        }
        return count;
    }
};