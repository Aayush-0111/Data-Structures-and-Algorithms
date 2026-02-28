class Solution {
const long long m = 1e9 + 7;
private:
    int stringToBinary(string& s){
        int n = s.size();
        long long ans = 0;
        long long p = 2;
        for(int i = 0; i < n; i++){
            ans = ((ans*2)%m + (s[i]-'0'))%m;
        }
        return ans;
    }
public:
    int concatenatedBinary(int n) {
        string s = "";
        for(int i = 1; i <= n; i++){
            int msb = 31 - __builtin_clz(i);
            for(int bit = msb; bit >= 0; bit--){
                s += ((i >> bit) & 1) + '0';
            }
        }
        int ans = stringToBinary(s);
        return ans;
    }
};