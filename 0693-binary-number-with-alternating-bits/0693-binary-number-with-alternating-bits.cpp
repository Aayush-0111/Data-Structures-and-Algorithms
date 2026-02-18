class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int v = (unsigned int)n + ((unsigned int)n >> 1);
        return ((v & (v+1)) == 0) ? true : false;
    }
};