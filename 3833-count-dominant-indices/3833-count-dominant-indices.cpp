class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        vector<int> suff(n,0);
        long long sum = 0;
        for(int i = n-2; i >= 0; i--){
            sum += nums[i+1];
            suff[i] = sum/(n-i-1);
        }
        for(int i = 0; i < n-1; i++){
            if(nums[i] > suff[i]){
                count++;
            }
        }
        return count;
    }
};