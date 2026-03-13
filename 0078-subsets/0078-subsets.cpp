class Solution {
public:
    vector<vector<int>> output;
    int n;
    void backTrack(int first, vector<int>& curr, vector<int>& nums){
        output.push_back(curr);
        for(int i = first; i < n; i++){
            curr.push_back(nums[i]);
            backTrack(i+1,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backTrack(0,curr,nums);
        return output;
;    }
};