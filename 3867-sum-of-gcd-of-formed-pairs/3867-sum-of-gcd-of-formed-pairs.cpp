class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = nums[0];
        for(int& i : nums){
            mx = max(mx,i);
            i = gcd(mx,i);
        }
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int s = 0, e = n-1;
        while(s < e) sum += gcd(nums[s++],nums[e--]);
        return sum;
    }
};