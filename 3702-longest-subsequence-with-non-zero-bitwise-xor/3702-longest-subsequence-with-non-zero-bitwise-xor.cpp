class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n{(int)nums.size()}, xr_All{0}, zero{0};
        for(int& i : nums){
            zero += (i) ? 0 : 1;
            xr_All ^= i;
        }
        if(zero == n) return 0;
        return (xr_All) ? n : n-1;
    }
};