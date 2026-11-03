class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi{*max_element(nums.begin(),nums.end())};
        return (int)nums.size()*maxi-accumulate(nums.begin(), nums.end(), 0LL);
    }
};