class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), l = 0, r = 0, m = 0, maxi = 0;
        int ones = count(s.begin(),s.end(),'1');
        int i = 0;
        while(i < n){
            int start = i;
            while(i < n && s[i] == s[start]) ++i;
            if(s[start] == '0'){
                ++m;
                r = i-start;
                maxi = (l != 0) ? max(maxi,r+l) : 0;
                l = r;
            }
        }
        if(m < 2) return ones;
        return ones + maxi;
    }
};