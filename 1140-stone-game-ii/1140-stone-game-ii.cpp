class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<int> suffixSum(n);
        suffixSum[n-1] = piles[n-1];
        for(int i{n-1}; i >= 1; --i){
            suffixSum[i-1] = suffixSum[i] + piles[i-1]; 
        }
        auto solve = [&](this auto&& solve, int i, int m) -> int {
            if(i >= n) return 0;
            // if you can choose all remaining piles, do it.
            if(i + 2*m >= n) return suffixSum[i];
            if(dp[i][m] != -1) return dp[i][m];
            int maxi = 0;
            for(int x{1}; i+x-1 < n && x <= 2*m; ++x){
                // opponent's optimal score
                int opponent_score = solve(i+x,max(m,x));
                // my optimal score = remaing total piles - opponent's optimal score
                int my_score = suffixSum[i] - opponent_score;
                // of all iterations/m's value , which will yield maximum socre
                // ex: if x == 2, our score can be 9 and if x == 3, it can be 19
                // something like that, you get the gist.
                // change in x value also impacts m value, which further impact opponent score.
                maxi = max(maxi,my_score);
            }
            return dp[i][m] = maxi;
        };
        return solve(0,1);
    }
};