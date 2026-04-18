class Solution {
public:
    int mirrorDistance(int n) {
        auto reverse = [](int n){
            int x = 0;
            while(n){
                x = x*10 + n%10;
                n /= 10;
            }
            return x;
        };
        return abs(n-reverse(n));
    }
};