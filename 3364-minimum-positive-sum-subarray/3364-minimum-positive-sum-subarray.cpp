class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini{INT_MAX};
        int n = nums.size();
        for(int i{0}; i < n; ++i){
            int sum{0}, len{0};
            for(int j{i}; j < n; ++j){
                sum += nums[j];
                ++len;
                if(sum > 0 && len >= l && len <= r){
                    mini = min(mini,sum);
                }
                if(len > r) break;
            }
        }
        return mini != INT_MAX ? mini : -1;
    }
};