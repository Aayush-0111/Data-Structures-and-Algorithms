class Solution {
public:
    static constexpr int MIN = -50000001;
    static inline string s[] = {"Bob", "Tie", "Alice"};
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n,MIN);
        auto maxDiff = [&](this auto&& maxDiff, int i) -> int {
            if(i == n) return 0;
            int& maxi = dp[i];
            if(maxi != MIN) return maxi;
            maxi = max(maxi,stoneValue[i] - maxDiff(i+1));
            if(i+1 < n) maxi = max(maxi,stoneValue[i]+stoneValue[i+1]-maxDiff(i+2));
            if(i+2 < n) maxi = max(maxi,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-maxDiff(i+3));
            return maxi;
        };
        int maxi = maxDiff(0);
        return s[(maxi > 0) - (maxi < 0) + 1];
    }
};