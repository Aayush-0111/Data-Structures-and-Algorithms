class Solution {
private:
    bool check(vector<int>& nums, int i, int j){
        for(int k = i; k < j; k++) if(nums[k] == nums[j]) return true;
        return false;
    }
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j{i}; j < nums.size(); j++){
            if(check(nums,i,j)) continue;
            swap(nums[i],nums[j]);
            solve(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i = 0;
        vector<vector<int>> ans;
        solve(nums,i,ans);
        return ans;
    }
};