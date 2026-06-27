class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0, balance = 0, Scurr = 0;
        vector<long long> frq(2*n+1,0);
        frq[n] = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                Scurr += frq[balance+n];
                ++balance;
            }else{
                --balance;
                Scurr -= frq[balance+n];
            }
            ++frq[balance+n];
            ans += Scurr;
        }
        return ans;
    }
};