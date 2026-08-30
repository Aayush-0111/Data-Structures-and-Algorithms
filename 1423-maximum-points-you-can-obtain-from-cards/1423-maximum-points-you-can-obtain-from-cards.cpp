class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalScore = accumulate(cardPoints.begin(),cardPoints.end(), 0);
        if(k == n) return totalScore;
        int maxScore{0};
        int subArrScore{0}, l{0}, r{0};
        while(r < n-k){
            subArrScore += cardPoints[r++];
        }
        maxScore = max(maxScore,totalScore-subArrScore);
        while(r < n){
            subArrScore -= cardPoints[l++];
            subArrScore += cardPoints[r++];
            maxScore = max(maxScore,totalScore - subArrScore);
        }
        return maxScore;
    }
};