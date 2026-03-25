class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long total_sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                total_sum += grid[i][j];
            }
        }
        long long running_sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                running_sum += grid[i][j];
            }
            if(running_sum == (total_sum - running_sum)) return true;
        }
        running_sum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                running_sum += grid[j][i];
            }
            if(running_sum == (total_sum - running_sum)) return true;
        }
        return false;
    }
};