class Solution {
public:
    const long long mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), xr = 0;
        for(int i = 0; i < m; i++){
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            int idx = l;
            while(idx <= r){
                nums[idx] = ((nums[idx]%mod)*v)%mod;
                idx += k;
            }
        }
        for(int i : nums){
            xr ^= i;
        }
        return xr;
    }
};