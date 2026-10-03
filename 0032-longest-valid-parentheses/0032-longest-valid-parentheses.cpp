class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int l{0}, r{0}, ans{0};
        for(char& c : s){
            if(c == '(') ++l;
            else ++r;
            if(l == r) ans = max(ans,2*r);
            else if(r > l) l = r = 0;
        }
        l = r = 0;
        for(int i{n-1}; i >= 0; --i){
            char c{s[i]};
            if(c == '(') ++l;
            else ++r;
            if(l == r) ans = max(ans,2*l);
            else if(l > r) l = r = 0; 
        }
        return ans;
    }
};