class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.push_back({});
        for(int i = 0; i < n; i++){
            auto x = ans;
            for(auto p : x){
                auto v = p;
                v.push_back(nums[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};