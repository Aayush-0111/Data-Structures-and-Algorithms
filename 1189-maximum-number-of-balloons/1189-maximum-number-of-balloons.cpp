class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        int frq[26] = {0};
        for(char& c : text) frq[c-'a']++;
        return min({frq[0],frq[1],frq['l'-'a']>>1,frq['o'-'a']>>1,frq['n'-'a']});
    }
};