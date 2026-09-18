class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int count{1};
        // every imbalance accounts for a new "abc" group. if we wind out how many groups of "abc" there are,
        // we can count the minimum number of letters by subtracting word.size() from total number of characters
        // "abc" -> 3 chars so -> 3*(no. of groups) - word.size() is our answer.
        for(int i{1}; i < n; ++i) if(word[i] <= word[i-1]) ++count;
        return 3*count - n;
    }
};