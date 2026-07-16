class Solution {
private:
    void solve(vector<int>& nums, vector<int> op, int i, vector<vector<int>>& ans){
        // base case
        if(i >= nums.size()){
            ans.push_back(op);
            return;
        }
        // inclusion
        op.push_back(nums[i]);
        solve(nums,op,i+1,ans);
        op.pop_back();
        // exclusion
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        solve(nums,op,i+1,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> ans;
        vector<int> op;
        ans.reserve(pow(2,n));
        sort(nums.begin(),nums.end());
        solve(nums,op,i,ans);
        return ans;
    }
};