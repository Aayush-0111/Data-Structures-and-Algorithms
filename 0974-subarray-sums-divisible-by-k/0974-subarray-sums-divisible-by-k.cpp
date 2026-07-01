class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        vector<int> p;
        unordered_map<int,int> mp;
        for(int& i : nums) p.push_back(sum = (sum+i%k+k)%k);
        for(int i = 0; i < n; i++){
            ans += (p[i]%k == 0) ? 1 : 0;
            int x = (p[i])%k;
            ans += (mp.count(x)) ? mp[x] : 0;
            mp[p[i]]++;
        }
        return ans;
    }
};