class Solution {
const long long mod = 1e9+9;
public:
    int bitwiseComplement(int n) {
        bitset<32> x(n);
        string s = x.to_string();
        auto t = s.find_first_not_of("0");
        if(t != string::npos){
            s.erase(s.begin(),s.begin()+t);
        }else{
            return 1;
        }
        int ans = 0;
        for(char c : s){
            if(c == '0'){
                ans = (ans*2%mod + 1)%mod;
            }else{
                ans = ans*2%mod;
            }
        }
        return ans;
    }
};