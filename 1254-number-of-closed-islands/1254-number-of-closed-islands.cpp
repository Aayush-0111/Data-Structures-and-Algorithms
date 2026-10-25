class Solution {
private:
    void bfs(int x, int y, int& ans, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int m = grid.size(), n = grid[0].size();
        bool isClosed{true};
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = 1;
        int dirx[4] = {0,1,0,-1};
        int diry[4] = {-1,0,1,0};
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i{0}; i < 4; ++i){
                int r{x + dirx[i]}, c{y + diry[i]};
                if(r < 0 || r >= m || c < 0 || c >= n) isClosed = false;
                else if(grid[r][c] == 0 && !visited[r][c]){
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }
        ans += isClosed ? 1 : 0;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans{0};
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i{0}; i < m; ++i){
            for(int j{0}; j < n; ++j){
                if(grid[i][j] == 0 && !visited[i][j]) bfs(i,j,ans,grid,visited);
            }
        }
        return ans;
    }
};