class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        while(k--) ans += 1LL*max(mul--,1)*nums[i--];
        return ans;
    }
};