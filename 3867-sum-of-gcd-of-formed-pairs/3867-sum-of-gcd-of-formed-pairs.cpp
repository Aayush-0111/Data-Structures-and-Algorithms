class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGCD(n,0);
        int mx = nums[0];
        for(int i = 0; i < n; i++){
            mx = max(mx,nums[i]);
            prefixGCD[i] = gcd(nums[i],mx);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        long long sum = 0;
        int s = 0, e = n-1;
        while(s < e) sum += gcd(prefixGCD[s++],prefixGCD[e--]);
        return sum;
    }
};