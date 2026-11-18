class Solution {
public:
    int minChanges(string s) {
        int ans{0};
        for(int i{0}; i < (int)s.size(); i+=2) ans += (s[i]^s[i+1]) != 0;
        return ans;
    }
};