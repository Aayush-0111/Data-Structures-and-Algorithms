class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // positions for which j-i is even can be odd-odd and even-even
        int n = s1.size();
        int vo1[26] = {0}, vo2[26] = {0}, ve1[26] = {0}, ve2[26] = {0};
        for(int i = 0; i < n; i++){
            if(i%2 == 0){
                ve1[s1[i]-'a']++;
                ve2[s2[i]-'a']++;
            }else{
                vo1[s1[i]-'a']++;
                vo2[s2[i]-'a']++;
            }
        }
        return ((equal(ve1,ve1+26,ve2)) && (equal(vo1,vo1+26,vo2)));
    }
};