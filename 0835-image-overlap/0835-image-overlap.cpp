class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans{0};
        vector<int> im1, im2;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                if(img1[i][j] == 1) im1.emplace_back(i*n+j); // can retrieve the idxs like i->i/n and j->j%n
                if(img2[i][j] == 1) im2.emplace_back(i*n+j);
            }
        }
        // offsets range from -(n-1) to (n-1) so we can use a vector instead of a map
        vector<vector<int>> offset(2*n-1,vector<int>(2*n-1,0));
        for(int& p : im1){
            for(int& q : im2){
                int dx{p/n - q/n}, dy{p%n - q%n};
                // shifting negative idx to positive
                dx += n-1;
                dy += n-1;
                ans = max(ans,++offset[dx][dy]);
            }
        }
        return ans;
    }
};