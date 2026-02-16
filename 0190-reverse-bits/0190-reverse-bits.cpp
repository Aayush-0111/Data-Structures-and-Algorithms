class Solution {
public:
    int reverseBits(int n) {
        bitset<32> x(n);
        for(int i = 0; i < 16; i++){
            bool temp = x[i];
            x[i] = x[31-i];
            x[31-i] = temp;
        }
        unsigned long long y = x.to_ullong();
        return (int)y;
    }
};