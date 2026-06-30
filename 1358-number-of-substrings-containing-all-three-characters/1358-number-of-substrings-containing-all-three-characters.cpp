class Solution {
public:
    int numberOfSubstrings(string s) {
        // track the last pos of a,b,c and if all are present
        // every substring from that point onwards till the starting is valid
        // minimum of the last seen pos of a,b,c is the point from which every every
        // substring we make till pos = 0 is valid
        // ex: abcab, posC = 2 and from that we have 0,1,2 as valid starting points for our valid substrs.

        int n = s.size(), ans = 0;
        int frq[3] = {-1,-1,-1};
        for(int i = 0; i < n; i++){
            frq[s[i]-'a'] = i;
            int k = min({frq[0],frq[1],frq[2]});
            if(k < 0) continue;
            ans += k+1;
        }
        return ans;
    }
};