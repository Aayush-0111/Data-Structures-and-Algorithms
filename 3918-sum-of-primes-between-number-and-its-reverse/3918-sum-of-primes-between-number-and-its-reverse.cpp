class Solution {
private:
    void sieve(vector<bool>& prime){
        prime[1] = false;
        for(int p = 2; p*p <= 1000; p++){
            if(prime[p]){
                for(int i = p*p; i <= 1000; i+=p){
                    prime[i] = false;
                }
            }
        }
    }
    int rev(int n){
        int r = 0;
        while(n){
            int x = n%10;
            r = r*10 + x;
            n /= 10;
        }
        return r;
    }
public:
    int sumOfPrimesInRange(int n) {
        vector<bool> prime(1001,true);
        sieve(prime);
       
        int ans = 0;
        int r = rev(n);
         cout << r << '\n';
        for(int i = min(n,r); i <= max(n,r); i++){
            if(prime[i]) {
                ans += i;
            }
        }
        return ans;
    }
};