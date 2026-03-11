class Solution {
public:
    int findComplement(int num) {
        bitset<32> x(num);
        int ans = 0;
        string s = x.to_string();
        auto t = s.find_first_not_of("0");
        if(t != string::npos){
            s.erase(0,t);
        }else{
            return 1;
        }
        for(char& c : s){
            ans = ((ans << 1) + (c == '0'));
        }
        return ans;
    }
};