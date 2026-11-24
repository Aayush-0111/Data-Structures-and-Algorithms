class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans{0};

        for(int i{0}; i < n; ++i){
            __int128 g{0}, l{1}, prod{1};

            for(int j{i}; j < n; ++j){
                g = gcd((long long)g, (long long)nums[j]);
                l = l / gcd((long long)l, (long long)nums[j]) * nums[j];
                prod *= nums[j];
                if (prod > g * l) {
                    break;
                }
                if(prod == g*l) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};