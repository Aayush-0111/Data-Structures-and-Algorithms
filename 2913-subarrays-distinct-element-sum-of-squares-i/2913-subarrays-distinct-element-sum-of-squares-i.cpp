static int seen[101];
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans{0};
        for(int i{0}; i < n; ++i){
            int count{0};
            memset(seen,0,sizeof(seen));
            for(int j{i}; j < n; ++j){
                ++seen[nums[j]];
                seen[nums[j]] == 1 ? ++count : count += 0;
                ans += count*count;
            }
        }
        return ans;
    }
};