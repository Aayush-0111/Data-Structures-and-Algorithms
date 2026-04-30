class Solution {
    const int m = 1e5+2;
private:
    void sieve(int n, vector<bool>& prime){
        prime[1] = false;
        for(int p = 2; p*p <= n; p++){
            if(prime[p]){
                for(int i = p*p; i <= n; i+=p){
                    prime[i] = false;
                }
            }
        }
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = 0;
        vector<bool> prime(m+1,true);
        sieve(m,prime);
        // processing odd
        for(int i = 1; i < n; i+=2){
            if(prime[nums[i]]){
                int prev = nums[i], next = -1;
                while(nums[i] <= m && prime[nums[i]]){
                    nums[i]++;
                    if(!prime[nums[i]]) {
                        minOps += nums[i] - prev;
                        break;
                    }
                }
            }
        }
        // processing even
        for(int i = 0; i < n; i+=2){
            if(prime[nums[i]]) continue;
            else{
                int prev = nums[i];
                while(nums[i] <= m && !prime[nums[i]]){
                    nums[i]++;
                    if(prime[nums[i]]){
                        minOps += nums[i] - prev;
                        break;
                    }
                }
            }
        }
        return minOps;
    }
};