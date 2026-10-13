class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int& i : nums) if(i < 0) i = -i;
        sort(nums.begin(), nums.end());
        int i{0}, j{n-1};
        long long ans{0};
        while(i < j) ans += nums[j]*nums[j--] - nums[i]*nums[i++];
        if(i == j) ans += nums[i]*nums[j];
        return ans;
    }
};