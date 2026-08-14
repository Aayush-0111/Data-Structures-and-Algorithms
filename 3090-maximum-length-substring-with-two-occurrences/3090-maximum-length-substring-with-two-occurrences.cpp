static int frq[26]; 
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n{(int)s.size()}, ans{0};
        memset(frq,0,sizeof(frq));
        int l{0};
        for(int r{0}; r < n; ++r){
            char c = s[r];
            ++frq[c-'a'];
            while(frq[c-'a'] > 2) --frq[s[l++]-'a'];
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};