class Solution {
private:   
    void solve(vector<int>& nums, vector<int> op, int i, vector<vector<int>>& ans){
        // base case
        if(i >= nums.size()) {
            ans.push_back(op);
            return;
        }

        // exclude
        solve(nums,op,i+1,ans);

        // include
        op.push_back(nums[i]);
        solve(nums,op,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> ans;
        ans.reserve(pow(2,n));
        vector<int> op;
        solve(nums,op,i,ans);
        return ans;
    }
};