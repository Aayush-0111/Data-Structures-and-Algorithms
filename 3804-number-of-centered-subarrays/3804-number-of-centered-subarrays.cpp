class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), count = n;
        if(n == 1) return 1;
        for(int i = 0; i < n-1; i++){
            unordered_map<int,int> mp;
            mp[nums[i]]++;
            int sum = nums[i];
            for(int j = i+1; j < n; j++){
                mp[nums[j]]++;
                sum += nums[j];
                if(mp.count(sum)) count++;
            }
        }
        return count;
    }
};