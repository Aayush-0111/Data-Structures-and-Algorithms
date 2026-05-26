class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), ans = 0;
        int frq1[26] = {0}, frq2[26] = {0};
        for(char& c : word){
            if(c >= 'a' && c <= 'z') frq1[c-'a']++;
            else frq2[c-'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(frq1[i] != 0 && frq2[i] != 0) ans++;
        }
        return ans;
    }
};