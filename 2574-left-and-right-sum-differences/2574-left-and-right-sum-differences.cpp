class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size(), l = 0;
        vector<int> ans(n);
        int sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i < n; i++){
            // l - (sum-l-nums[i])
            ans[i] = abs(2*l-sum+nums[i]);
            l += nums[i];
        }
        return ans;
    }
};