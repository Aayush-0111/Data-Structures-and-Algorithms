class Solution {
private:
    int maxDiff(vector<int>& A,int i, vector<int>& dp, int n){
        if(i >= n){
            return 0;
        }
        int& x = dp[i];
        if(x != MIN) return x;
        // Alice takes 1
        x = max(x,A[i] - maxDiff(A,i+1,dp,n));
        // Alice takes 2
        if(i+1 < n) x = max(x,A[i] + A[i+1] - maxDiff(A,i+2,dp,n));
        // Alice takes 3
        if(i+2 < n) x = max(x,A[i] + A[i+1] + A[i+2] - maxDiff(A,i+3,dp,n));

        return x;
    }
public:
    static constexpr int MIN = -50000001;
    static inline string s[] = {"Bob", "Tie", "Alice"};
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int x = MIN;
        vector<int> dp(n,MIN);
        int maxi = maxDiff(stoneValue,0,dp,n);
        return s[(maxi > 0) - (maxi < 0) + 1];
    }
};