class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), target = 0, sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);
        target = sum-x;
        if(target == 0) return n;
        if(target < 0) return -1;
        unordered_map<int,int> mp;
        int pre = 0, len = 0;
        for(int i = 0; i < n; i++){
            pre += nums[i];
            len = (pre == target) ? max(len,i+1) : len;
            int x = pre - target;
            len = (mp.count(x)) ? max(len,i-mp[x]) : len;
            mp[pre] = i;
        }
        return (len != 0) ? n-len : -1;
    }
};