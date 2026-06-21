class Solution {
private:
    int first(long long n){
        int fst = 0;
        while(n){
            fst = n%10;
            n /= 10;
        }
        return fst;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size(), ans = 0;
        // tackle individual elements
        for(int i = 0; i < n; i++){
            if(nums[i]%10 == x && first(nums[i]) == x) ans++;
        }
        for(int i = 0; i < n-1; i++){
            long long sum = nums[i];
            for(int j = i+1; j < n; j++){
                sum += nums[j];
                if(sum%10 == x && first(sum) == x) ans++;
            }
        }
        return ans;
    }
};