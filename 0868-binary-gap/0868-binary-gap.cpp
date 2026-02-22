class Solution {
public:
    int binaryGap(int n) {
        bitset<32> x(n);
        string t = x.to_string();
        size_t pos = t.find_first_not_of("0");
        string s = t.substr(pos);
        cout << s << "\n";
        int l = -1, m = s.size(), maxi = 0;
        for(int r = 0; r < m; r++){
            if(s[r] == '0' && l != -1){
                while(r < m && s[r] != '1'){
                    r++;
                }
                if(r == m && s[r-1] == '0'){
                    break;
                }
                maxi = max(maxi,r-l);
                l = r;
            }else if(s[r] == '1'){
                if(l != -1){
                    maxi = max(maxi,r-l);
                }
                l = r;
            }
        }
        return maxi;
    }
};