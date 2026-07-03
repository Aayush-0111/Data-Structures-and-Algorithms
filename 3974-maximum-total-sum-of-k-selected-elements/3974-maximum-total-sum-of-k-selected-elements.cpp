class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        while(k){
            ans += (mul > 0) ? 1LL*mul*nums[i] : nums[i];
            --k;
            --mul;
            --i;
        }
        return ans;
    }
};