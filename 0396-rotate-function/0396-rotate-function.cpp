class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), f = 0,sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i < n; i++){
            f += i*nums[i];
        }
        int ans = f;
        for(int i = n-1; i > 0; i--){
            f += sum - n*nums[i];
            ans = max(f,ans);
        }
        return ans;
    }
};