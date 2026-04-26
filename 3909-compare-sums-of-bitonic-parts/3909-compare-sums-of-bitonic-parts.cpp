class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0, sum2 = 0;
        bool flag = false;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(maxi == nums[i]) {
                flag = true;
                sum1 += nums[i];
            }
            if(!flag) sum1 += nums[i];
            else sum2 += nums[i];
        }
        if(sum1 > sum2) return 0;
        else if(sum2 > sum1) return 1;
        else return -1;
    }
};