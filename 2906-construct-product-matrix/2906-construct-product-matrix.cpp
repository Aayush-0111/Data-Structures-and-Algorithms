class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> product(n,vector<int>(m));
        const int mod = 12345;
        long long prefix = 1, suffix = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >=0; j--){
                product[i][j] = suffix;
                suffix = suffix*grid[i][j]%mod;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                product[i][j] = product[i][j]*prefix%mod;
                prefix = prefix*grid[i][j]%mod;
            }
        }
        return product;
    }
};