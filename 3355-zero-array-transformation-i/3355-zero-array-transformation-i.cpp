class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> diff(n,0);
        for(int i = 0; i < m; i++){
            int l = queries[i][0], r = queries[i][1];
            diff[l] -= 1;
            if(r < n-1) diff[r+1] += 1; 
        }
        vector<int> pre(n,0);
        pre[0] = diff[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + diff[i];
        }
        for(int i = 0; i < n; i++){
            nums[i] += pre[i];
            if(nums[i] > 0) return false;
        }
        return true;
    }
};