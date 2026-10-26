class Solution {
private:
    bool bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int sum{0};
        q.push({x,y});
        visited[x][y] = 1;
        int dirx[4] = {1,0,-1,0};
        int diry[4] = {0,1,0,-1};
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            sum += grid[x][y];
            for(int i{0}; i < 4; ++i){
                int r{x + dirx[i]}, c{y + diry[i]};
                if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || !grid[r][c]) continue;
                q.push({r,c});
                visited[r][c] = 1;
            }
        }
        return sum;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans{0};
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<vector<int>> grid2(m, vector<int>(n,0));
        for(int i{0}; i < m; ++i){
            for(int j{0}; j < n; ++j){
                grid2[i][j] = grid[i][j] - '0';
            }
        }
        for(int i{0}; i < m; ++i){
            for(int j{0}; j < n; ++j) if(!visited[i][j] && grid2[i][j] && bfs(i,j,grid2,visited)) ++ans;
        }
        return ans;
    }
};