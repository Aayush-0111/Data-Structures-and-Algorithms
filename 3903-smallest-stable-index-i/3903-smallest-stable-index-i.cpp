class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n,0);
        suff[n-1] = nums[n-1];
        for(int i{n-2}; i >= 0; --i) suff[i] = min(nums[i],suff[i+1]);
        int pre{INT_MIN}, stable{INT_MAX};
        for(int i{0}; i < n; ++i){
            pre = max(pre,nums[i]);
            if(pre-suff[i] <= k) {
                stable = i;
                break;
            }
        }
        return (stable != INT_MAX) ? stable : -1;
    }
};