class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        auto temp = mat;
        while(k--){
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    int first = mat[i][0];
                    for(int j = 1; j < m; j++){
                        mat[i][j-1] = mat[i][j];
                    }
                    mat[i][m-1] = first;
                }else{
                    int last = mat[i][m-1];
                    for(int j = m-2; j >= 0; j--){
                        mat[i][j+1] = mat[i][j];
                    }
                    mat[i][0] = last;
                }
            }
        }
        return (temp == mat);
    }
};