class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), maxi = -1, mini = nums[0];
        for(int i = 1; i < n; i++){
            maxi = max(maxi,nums[i]-mini);
            mini = min(mini,nums[i]);
        }
        return (maxi > 0) ? maxi : -1;
    }
};