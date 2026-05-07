class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        s = s.substr(s.find_first_not_of("0"));
        int l = -1, maxi = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] == '1' && l == -1) l = i;
            else if(s[i] == '1'){
                maxi = max(maxi,abs(l-i));
                l = i;
            }
        }
        return maxi;
    }
};