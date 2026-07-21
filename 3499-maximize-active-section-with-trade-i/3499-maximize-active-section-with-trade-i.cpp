class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), l = 0, m = 0, maxi = 0, ones = 0;
        int i = 0;
        while(i < n){
            int start = i;
            while(i < n && s[i] == s[start]) ++i;
            if(s[start] == '0'){
                ++m;
                maxi = (l != 0) ? max(maxi,i-start+l) : 0;
                l = i-start;
            }else ones += (i-start);
        }
        if(m < 2) return ones;
        return ones + maxi;
    }
};