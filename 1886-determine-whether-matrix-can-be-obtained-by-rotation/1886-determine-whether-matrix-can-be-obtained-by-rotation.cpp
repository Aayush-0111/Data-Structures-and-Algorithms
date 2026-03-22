class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        int n = mat.size();
        int x = 3;
        while(x--){
            vector<vector<bool>> check(n,vector<bool>(n,false));
            // Transpose and reverse each row
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    if(check[i][j]) continue;
                    swap(mat[i][j],mat[j][i]);
                    check[i][j] = true;
                    check[j][i] = true;
                }
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat == target) return true;
        }
        return false;
    }
};