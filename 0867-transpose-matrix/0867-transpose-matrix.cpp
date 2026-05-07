class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(m == n){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < m; j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            return matrix;
        }else{
            vector<vector<int>> ans(m,vector<int>(n));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    ans[j][i] = matrix[i][j];
                }
            }
            return ans;
        }
    }
};