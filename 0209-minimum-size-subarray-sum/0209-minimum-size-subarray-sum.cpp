class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, pre = 0, ans = n+1;
        for(int r = 0; r < n; r++){
            pre += nums[r];
            while(pre >= target){
                ans = min(ans,r-l+1);
                pre -= nums[l++];
            }
        }
        return (ans == n+1) ? 0 : ans;
    }
};