class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        int i = 0, ans = n;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            long long val = 1LL*k*nums[i];
            int j = upper_bound(nums.begin(),nums.end(),val) - nums.begin();
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};