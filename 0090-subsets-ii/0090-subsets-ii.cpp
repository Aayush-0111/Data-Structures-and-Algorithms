class Solution {
private:
    void solve(vector<int>& nums, vector<int> op, int i, vector<vector<int>>& ans,set<vector<int>>& st){
        // base case
        if(i >= nums.size()){
            if(!st.count(op)) {
                ans.push_back(op);
                st.insert(op);
            }
            return;
        }
        // exclusion
        solve(nums,op,i+1,ans,st);
        // inclusion
        op.push_back(nums[i]);
        solve(nums,op,i+1,ans,st);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size(), i = 0;
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> op;
        ans.reserve(pow(2,n));
        sort(nums.begin(),nums.end());
        solve(nums,op,i,ans,st);
        return ans;
    }
};