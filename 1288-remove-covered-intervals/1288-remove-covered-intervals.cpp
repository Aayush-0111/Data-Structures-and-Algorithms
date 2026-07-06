class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int x = intervals[0][0], y = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= x && intervals[i][1] <= y) ans++;
            else{
                x = intervals[i][0];
                y = intervals[i][1];
            }
        }
        return n-ans;
    }
};