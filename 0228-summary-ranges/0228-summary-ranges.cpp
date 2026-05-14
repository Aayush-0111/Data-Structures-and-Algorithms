class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        vector<string> ans;
        for(int i = 0; i < n; i++){
            l = nums[i];
            r = nums[i];
            while(i < n-1 && nums[i+1] == nums[i]+1){
                r = nums[i+1];
                i++;
            }
            if(l != r){
                ans.push_back(to_string(l) + "->" + to_string(r));
            }else ans.push_back(to_string(l));
        }
        return ans;
    }
};