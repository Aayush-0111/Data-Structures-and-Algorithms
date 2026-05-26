class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        vector<int> f1(26,0), f2(26,0);
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(!isupper(c) && !f1[c-'a']){
                f1[c-'a'] = 1;
            }else if(isupper(c) && !f2[c-'A']){
                f2[c-'A'] = 1;
            }
        } 
        for(int i = 25; i >= 0; i--){
            if(f2[i] && f1[i]) return string(1,i+'A');
        }
        return "";
    }
};