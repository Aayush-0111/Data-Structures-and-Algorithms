class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1,dp) + solve(n-2,dp);
        return dp[n];
    }
public:
    int fib(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1,-1);
        dp[0] = 0; dp[1] = 1;
        return solve(n,dp);
    }
};