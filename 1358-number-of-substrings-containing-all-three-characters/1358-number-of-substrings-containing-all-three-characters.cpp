class Solution {
public:
    bool hasAll(int *frq){
        return (frq[0] && frq[1] && frq[2]);
    }
    int numberOfSubstrings(string s) {
        int n = s.size(), l = 0, ans = 0;
        int frq[3] = {0};
        for(int r = 0; r < n; r++){
            char c = s[r];
            frq[c-'a']++;
            while(hasAll(frq)){
                ans += n-r; // every extension(to the right) of a valid window is also valid.
                // like [l,r] -> valid, so is [l,r+1],[l,r+2]...[l,n-1] so n-r is representing just that.
                --frq[s[l++]-'a'];
            }
        }
        return ans;
    }
};