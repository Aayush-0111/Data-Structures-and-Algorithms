#define ll long long
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), balance = 0, Scurr = 0;
        vector<ll> frq(2*n+1,0);
        ll ans = 0;
        frq[n] = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                Scurr += frq[balance+n];
                ++balance;
                frq[balance+n]++;
            }else{
                Scurr -= frq[balance-1+n];
                --balance;
                frq[balance+n]++;
            }
            ans += Scurr;
        }
        return ans;
    }
};