bool frq1[26] = {false}, frq2[26] = {false};
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        int frq1[26] = {0}, frq2[26] = {0};
        for(char& c : word){
            if(c >= 'a' && c <= 'z' && !frq1[c-'a']) frq1[c-'a'] = true;
            else if(c >= 'A' && c <= 'Z' && !frq2[c-'A']) frq2[c-'A'] = true;
        }
        for(int i = 0; i < 26; i++){
            if(frq1[i] && frq2[i]) ans++;
        }
        memset(frq1,false,26);
        memset(frq2,false,26);
        return ans;
    }
};