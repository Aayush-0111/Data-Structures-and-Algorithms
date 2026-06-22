class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int frq1[26] = {0}, frq2[26] = {0};
        int n = s.size(), mini = n;
        for(char& c : target) frq1[c-'a']++;
        for(char&c : s) frq2[c-'a']++;
        for(int i = 0; i < 26; i++){
            if(frq1[i] == 0) continue;
            mini = min(mini,frq2[i]/frq1[i]);
        }
        return mini;
    }
};