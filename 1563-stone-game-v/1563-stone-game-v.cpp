vector<vector<int>> dp;
vector<int> prefix;
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n{(int)stoneValue.size()};
        prefix.assign(n+1,0);
        dp.assign(n,vector<int>(n));
        for(int i{0}; i < n; ++i) prefix[i+1] = prefix[i] + stoneValue[i];
        for(int len{0}; len <= n; ++len){
            for(int l{0}; l+len <= n; ++l){
                int r = l+len-1;
                // split points
                for(int k{l}; k < r; ++k){
                    int leftSum{prefix[k+1]-prefix[l]};
                    int rightSum{prefix[r+1]-prefix[k+1]};
                    if(leftSum < rightSum){
                        // leftSum + sum that will be obtained through the splitted sub-array.
                        dp[l][r] = max(dp[l][r], leftSum + dp[l][k]);
                    }else if(leftSum > rightSum){
                        dp[l][r] = max(dp[l][r],rightSum + dp[k+1][r]);
                    }else{
                        // sum + whichever side gives the higher value for future splits.
                        dp[l][r] = max(dp[l][r], leftSum + max(dp[l][k],dp[k+1][r]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};