bitset<101> seen;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        seen.reset();
        vector<int> ans;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        for(auto& i : nums) seen.set(i);
        for(int i{mini}; i <= maxi; ++i) if(!seen.test(i)) ans.push_back(i);
        return ans; 
    }
};