class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre(n+1,0);
        for(int i{0}; i < n; ++i) pre[i+1] = pre[i] + stones[i];
        vector<int> dp(n);
        dp[n-1] = pre[n];
        for(int i{n-2}; i >= 1; --i){
            dp[i] = max(dp[i+1],pre[i+1]-dp[i+1]);
        }
        return dp[1];
    }
};