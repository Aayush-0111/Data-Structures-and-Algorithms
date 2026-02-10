class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> e,o;
            for(int j = i; j < n; j++){
                if(nums[j]%2 == 0 && !e.count(nums[j])) e.insert(nums[j]);
                if(nums[j]%2 != 0 && !o.count(nums[j])) o.insert(nums[j]);
                if(e.size() == o.size()) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};