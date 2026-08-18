static int frq1[51];
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n{(int)nums.size()}, ans{-1};
        static int frq2[51] = {0};
        memset(frq1,0,sizeof(frq1));
        for(int i{0}; i+k <= n; ++i){
            int l{i};
            while(l < i+k){
                frq2[nums[l]] = 1;
                ++l;
            }
            for(int j{0}; j <= 50; ++j) frq1[j] += frq2[j];
            memset(frq2,0,sizeof(frq2));
        }
        for(int i{0}; i <= 50; ++i) if(frq1[i] == 1) ans = i;
        return ans;
    }
};