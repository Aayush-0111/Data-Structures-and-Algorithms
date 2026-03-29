class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < k; i++){
            if(nums[i] > nums[i+k]) sum += nums[i];
        }
        for(int i = n-1; i > n-k-1; i--){
            if(nums[i] > nums[i-k]) sum += nums[i];
        }
        for(int i = k; i <= n-k-1; i++){
            if(nums[i] > nums[i-k] && nums[i] > nums[i+k]) sum += nums[i];
        }
        return sum;
    }
};