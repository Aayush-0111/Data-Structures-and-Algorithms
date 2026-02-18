class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> x(n);
        string num = x.to_string();
        std::size_t found = num.find_first_not_of("0");
        for(size_t i = found; i < (int)num.size(); i++){
            if(num[i] == num[i-1]) return false;
        }
        return true;
    }
};