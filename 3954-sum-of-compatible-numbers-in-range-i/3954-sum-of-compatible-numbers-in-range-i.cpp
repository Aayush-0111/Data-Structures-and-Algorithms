class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        int x = 0;
        while(x <= n){
            sum += (n-x <= k && !(n&x)) ? x : 0;
            x++;
        }
        while(x-n <= k){
            sum += !(n&x) ? x : 0;
            x++;
        }
        return sum;
    }
};