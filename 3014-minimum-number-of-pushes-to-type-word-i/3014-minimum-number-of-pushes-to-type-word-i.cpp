class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), k = n >> 3, rem = n&7;
        return (4*k*(k+1) + (rem*(k+1)));
    }
};