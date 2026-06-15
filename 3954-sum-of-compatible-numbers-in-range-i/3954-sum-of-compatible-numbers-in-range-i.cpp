class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int x = max(1,n-k); x <= n+k; x++) sum += !(n&x) ? x : 0;
        return sum;
    }
};