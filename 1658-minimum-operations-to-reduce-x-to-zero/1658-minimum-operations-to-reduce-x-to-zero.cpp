class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = n;
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        if(target < 0) return -1;
        if(target == 0) return n;
        int l = 0, sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(l < n && sum > target) sum -= nums[l++];
            ans = (sum == target) ? min(ans,n-(r-l+1)) : ans;
        }
        return (ans == n) ? -1 : ans;
    }
};