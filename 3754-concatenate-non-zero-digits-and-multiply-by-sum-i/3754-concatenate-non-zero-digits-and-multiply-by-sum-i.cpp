class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum = 0, p = 1, x = 0;
        reverse(s.begin(),s.end());
        for(char c : s){
            if(c == '0') continue;
            int l = c-'0';
            x += l*p;
            p *= 10;
            sum += l;
        }
        return 1LL*x*sum;
    }
};