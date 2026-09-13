class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans{0};
        vector<pair<int,int>> im1, im2;
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                if(img1[i][j] == 1) im1.push_back({i,j});
                if(img2[i][j] == 1) im2.push_back({i,j});
            }
        }
        unordered_map<pair<int,int>,int, pair_hash> offset;
        for(auto& p : im1){
            for(auto& q : im2){
                const pair<int,int> offs = {p.first-q.first,p.second-q.second};
                ans = max(ans,++offset[offs]);
            }
        }
        return ans;
    }
};