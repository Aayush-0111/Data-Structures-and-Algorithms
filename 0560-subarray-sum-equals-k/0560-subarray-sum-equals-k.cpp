class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        vector<int> prefix;
        unordered_map<int,int> mp;
        for(int& i : nums) prefix.push_back(sum += i);
        for(int i = 0; i < n; i++){
            ans += (prefix[i] == k) ? 1 : 0;
            int x = prefix[i]-k;
            ans += (mp.count(x)) ? mp[x] : 0;
            mp[prefix[i]]++;
        }
        return ans;
    }
};