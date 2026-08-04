static bool frq[101] = {false};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        memset(frq,false,sizeof(frq));
        vector<int> ans;
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        for(int& i : nums) frq[i] = true;
        for(int i{mini}; i <= maxi; ++i) if(!frq[i]) ans.push_back(i);
        return ans;
    }
};