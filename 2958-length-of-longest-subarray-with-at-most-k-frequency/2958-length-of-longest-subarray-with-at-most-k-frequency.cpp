class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, ans = 0;
        unordered_map<int,int> frq;
        for(int r = 0; r < n; ++r){
            ++frq[nums[r]];
            while(l <= r && frq[nums[r]] > k){
                --frq[nums[l++]];
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};