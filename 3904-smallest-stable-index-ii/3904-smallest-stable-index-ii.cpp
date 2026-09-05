class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n,0);
        suff[n-1] = nums[n-1];
        for(int i{n-2}; i >= 0; --i) suff[i] = min(nums[i],suff[i+1]);
        int pre{INT_MIN};
        for(int i{0}; i < n; ++i){
            pre = max(pre,nums[i]);
            if(pre-suff[i] <= k) return i;
        }
        return -1;
    }
};