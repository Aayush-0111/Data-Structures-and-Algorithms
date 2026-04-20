class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxP = 0, mini = prices[0];
        for(int i = 1; i < n; i++){
            maxP = max(maxP,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return (maxP > 0) ? maxP : 0;
    }
};