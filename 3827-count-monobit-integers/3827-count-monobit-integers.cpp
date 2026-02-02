class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;
        if(((n+1) & n) == 0) return 32 - __builtin_clz(n) + 1;
        return 32 - __builtin_clz(n);
    }
};