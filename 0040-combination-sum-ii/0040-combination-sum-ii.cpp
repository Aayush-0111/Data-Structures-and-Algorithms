class Solution {
private:
    void solve(vector<int>& nums, int i, vector<int> op, vector<vector<int>>& ans, int t){
        if(t == 0){
            ans.push_back(op);
            return;
        }
        if(i >= nums.size() || t < 0) return;
        //include
        op.push_back(nums[i]);
        solve(nums,i+1,op,ans,t-nums[i]);
        op.pop_back();
        //exclude
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        solve(nums,i+1,op,ans,t);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i = 0;
        sort(candidates.begin(),candidates.end());
        vector<int> op;
        vector<vector<int>> ans;
        solve(candidates,i,op,ans,target);
        return ans;
    }
};