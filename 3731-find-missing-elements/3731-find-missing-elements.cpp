class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        vector<bool> frq(maxi+1,false);
        for(int& i : nums) frq[i] = true;
        for(int i{mini}; i <= maxi; ++i) if(!frq[i]) ans.push_back(i);
        return ans;
    }
};