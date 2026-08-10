class Solution {
    vector<int8_t> dp;
private:
    bool solve(int n){
        // if n == 0, current player already lost.
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i*i <= n; ++i){
            // if there is a square number to be removed, and it can force opponent's loss
            // the current player wins,
            if(!solve(n-i*i)) return dp[n] = true;
        }
        return dp[n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        dp[0] = false;
        return solve(n);
    }
};