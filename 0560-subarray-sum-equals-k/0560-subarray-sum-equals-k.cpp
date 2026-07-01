class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        vector<int> prefix;
        unordered_map<int,int> mp;
        for(int& i : nums) prefix.push_back(sum += i);
        for(int i = 0; i < n; i++){
            if(prefix[i] == k) ++ans;
            int x = prefix[i]-k;
            if(mp.count(x)) ans += mp[x];
            mp[prefix[i]]++;
        }
        return ans;
    }
};