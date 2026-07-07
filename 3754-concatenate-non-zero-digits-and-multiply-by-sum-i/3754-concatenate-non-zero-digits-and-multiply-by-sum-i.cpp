class Solution {
private:
    long long dig(int n){
        long long x = 0;
        while(n){
            if(n%10 == 0) {
                n /= 10;
                continue;
            }
            x = x*10 + n%10;
            n /= 10;
        }
        long long ans = 0;
        while(x){
            ans = ans*10 + x%10;
            x /= 10;
        }
        return ans;
    }
    long long sum(int n){
        long long ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
public:
    long long sumAndMultiply(int n) {
        return 1LL*dig(n)*sum(n);
    }
};