class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        for(int i{1}; i < n; ++i) answer[i] = nums[i-1]*answer[i-1];
        long long suff{nums[n-1]};
        for(int i{n-2}; i >= 0; --i){
            answer[i] *= suff;
            suff *= nums[i];
        }
        return answer;
    }
};