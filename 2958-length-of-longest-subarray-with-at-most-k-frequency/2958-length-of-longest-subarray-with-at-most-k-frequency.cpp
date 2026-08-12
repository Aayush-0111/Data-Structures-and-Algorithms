class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n{(int)nums.size()}, l{0}, ans{0};
        unordered_map<int,int> frq;
        frq.reserve(n);
        for(int r = 0; r < n; ++r){
            int x = nums[r];
            auto it = frq.find(x);
            int& f = (it == frq.end()) ? frq[x] = 1 : ++(it->second);
            while(f > k) --frq[nums[l++]];
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};