class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0;
        for(int& i : nums) if(i == target) ++ans;
        for(int i = 0; i < n-1; i++){
            int count = 0;
            if(nums[i] == target) count++;
            for(int j = i+1; j < n; j++){
                if(nums[j] == target) count++;
                ans += (2*count > j-i+1) ? 1 : 0;
            }
        }
        return ans;
    }
};