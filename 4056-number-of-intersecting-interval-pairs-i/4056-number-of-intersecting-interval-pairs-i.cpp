class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans{0};
        for(int i{0}; i < n; ++i){
            int start{intervals[i][0]}, end{intervals[i][1]};
            int j{i+1};
            while(j < n){
                ans += (end < intervals[j][0] || start > intervals[j][1]) ? 0 : 1;
                ++j;
            }
        }
        return ans;
    }
};