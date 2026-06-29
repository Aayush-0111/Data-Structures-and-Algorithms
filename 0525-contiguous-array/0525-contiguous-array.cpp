class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int balance = 0, ans = 0;
        unordered_map<int,int> mp;
        // assign 0 -> -1 and 1 -> +1
        // for i < j and balance at  i == balance at j
        // means number of 1 and 0 b/w i & j is equal.
        // cause balance represent prefix sum, so for sum to be equal
        // for i and j, there has to be equal no. of 1 and -1 till j
        // making the resulting sum = 0 and balance unchanged
        mp[0] = -1; // in case, answer array starts at 0th index.
        for(int i = 0; i < n; i++){
            balance += (nums[i] == 1) ? 1 : -1;
            if(!mp.count(balance)) mp[balance] = i;
            else ans = max(ans,i-mp[balance]);
        }
        return ans;
    }
};