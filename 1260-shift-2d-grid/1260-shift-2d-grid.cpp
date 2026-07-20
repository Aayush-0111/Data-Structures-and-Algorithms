class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> v;
        v.reserve(m*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v.push_back(grid[i][j]);
            }
        }
        int sft = k%(v.size());
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+sft);
        reverse(v.begin()+sft,v.end());
        int z = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = v[z++];
            }
        }
        return grid;
    }
};