class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n < 3) return 0;
        int ones = 0, zeroes = 0;
        for(char& c : s){
            if(c == '0') zeroes++;
            ones = n - zeroes;
        }
        if(s[0] == '1' && s[n-1] == '1') return min(zeroes,ones-2);
        return (ones > 0) ? min(zeroes,ones-1) : 0;
    }
};