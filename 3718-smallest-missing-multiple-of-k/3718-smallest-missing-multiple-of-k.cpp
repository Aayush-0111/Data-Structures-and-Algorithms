class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size(), maxi = *max_element(nums.begin(),nums.end());
        int m{maxi+k+1};
        vector<int> frq(m);
        for(int& i : nums) frq[i] = 1;
        for(int i{1}; i <= m/k; ++i){
            if(i*k <= m && !frq[i*k]) return i*k;
        }
        return 1;
    }
};