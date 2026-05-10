class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        auto it = find(nums.begin(),nums.end(),1);
        if(it != nums.end()){
            return 1LL*n;
        }
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> sieve(maxi+1);
        for(int i : nums){
            sieve[i] = i;
        }
        sort(nums.begin(),nums.end());
        for(int a : nums){
            if(sieve[a] == a){
                for(int b = a; b <= maxi; b+=a){
                    if(sieve[b] == b){
                        sieve[b] = a;
                    }
                }
            }
        }
        long long ans = 0;
        for(int i : nums){
            ans += sieve[i];
        }
        return ans;
    }
};