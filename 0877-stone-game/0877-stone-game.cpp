class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // since number of piles are even and Alice plays first,
        // she can force bob to either take all the even idx piles or odd idx piles
        // and since they are playing optimally, Alice will choose the parity with most stones.
        // so in this game, Alice will always win under given conditions.
        return true;
    }
};