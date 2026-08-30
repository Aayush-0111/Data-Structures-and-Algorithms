class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = min_element(nums.begin(),nums.end()) - nums.begin() +1;
        int maxi = max_element(nums.begin(),nums.end()) - nums.begin() +1;
        int ans{0}, diff{abs(mini-maxi)};
        // Take minimum of the three:
        // Both del from front, Both from back and Front and back.
        ans = min(min(mini,maxi)+n+1-max(mini,maxi), min(min(mini,maxi)+diff, min(n-mini,n-maxi)+diff+1));
        return ans;
    }
};