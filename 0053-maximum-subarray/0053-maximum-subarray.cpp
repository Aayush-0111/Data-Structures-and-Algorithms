class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, sum = 0;
        for(int &i : nums){
            if(sum < 0) sum = 0;
            sum += i;
            ans = max(ans,sum);
        }
        return ans;
    }
};