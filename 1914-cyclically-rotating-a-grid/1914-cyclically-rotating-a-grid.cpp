class Solution {
private:
    vector<int> extractLayer(vector<vector<int>>& grid, int r, int c, int row, int col){
        vector<int> layer;
        // first column
        for(int i = r; i <= row; i++){
            layer.push_back(grid[i][c]);
        }
        c++;
        // last row
        for(int i = c; i <= col; i++){
            layer.push_back(grid[row][i]);
        }
        row--;
        // last column
        for(int i = row; i >= r; i--){
            layer.push_back(grid[i][col]);
        }
        col--;
        // first row
        for(int i = col; i >= c; i--){
            layer.push_back(grid[r][i]);
        }
        r++;
        return layer;
    }
    void rotate(vector<int>& layer,int k){
        int n = layer.size();
        k %= n;
        reverse(layer.begin(),layer.end());
        reverse(layer.begin(),layer.begin()+k);
        reverse(layer.begin()+k,layer.end());
    }
    void reArrange(vector<vector<int>>& grid, vector<int>& layer,int r, int c, int row, int col){
        int j = 0, n = layer.size();
        for(int i = r; j < n && i <= row; i++){
            grid[i][c] = layer[j++];
        }
        c++;
        for(int i = c; j < n && i <= col; i++){
            grid[row][i] = layer[j++];
        }
        row--;
        for(int i = row; j < n && i >= r; i--){
            grid[i][col] = layer[j++];
        }
        col--;
        for(int i = col; j < n && i >= c; i--){
            grid[r][i] = layer[j++];
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size()-1, col = grid[0].size()-1, r = 0, c = 0;
        int x = min(row+1,col+1)/2;
        while(x--){
            vector<int> layer = extractLayer(grid,r,c,row,col);
            rotate(layer,k);
            reArrange(grid,layer,r,c,row,col);
            c++; row--; col--; r++;
        }
        return grid;
    }
};