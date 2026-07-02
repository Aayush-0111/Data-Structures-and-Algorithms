class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), ans = n;
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        long long k = sum%p;
        if(k == 0) return 0;
        unordered_map<int,int> mp;
        vector<long long> pre;
        long long s = 0;
        // Initial condition is Sum%p = 0.
        // so removing X from sum will make the sum divisible by p.
        // (sum-x)%p == 0 => sum%p = x%p
        for(int& i : nums) pre.push_back(s += 1LL*i);
        for(int i = 0; i < n; i++){
            ans = (pre[i]%p == k) ? min(ans,i+1) : ans;
            // target = sum%p
            // in terms of prefix sum, (pre[i]-pre[j])%p = target => (pre[i]-target)%p = pre[j]%p
            int x = (pre[i]-k+p)%p;
            ans = (mp.count(x)) ? min(ans,i-mp[x]) : ans;
            mp[pre[i]%p] = i;
        }
        return (ans != n) ? ans : -1;
    }
};