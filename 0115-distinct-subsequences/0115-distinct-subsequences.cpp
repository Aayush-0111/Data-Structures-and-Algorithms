class Solution {
private:
    int solve(string s, string t, int i, int j, vector<vector<int>>& dp){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            // take
            ans = solve(s,t,i+1,j+1,dp);
            // skip
            ans += solve(s,t,i+1,j,dp);
        }else ans += solve(s,t,i+1,j,dp); // if curr letters don't match
        // we check whether the rest following letters of s can match t's letters
        // dp[i][j] = dp[i+1][j];
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m) return 0;
        if(n == m) return s == t;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,0,0,dp);
    }
};