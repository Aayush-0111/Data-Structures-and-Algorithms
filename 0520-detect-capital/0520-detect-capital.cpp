class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int capCnt = 0;
        for(char& c : word) if(isupper(c)) capCnt++;
        // All uppercase or no uppercase
        if(capCnt == n || capCnt == 0) return true;
        // Starting upper and rest lower
        if(isupper(word[0]) && capCnt == 1) return true;
        // Rest all invalid
        return false;
    }
};