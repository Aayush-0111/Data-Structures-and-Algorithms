class Solution {
private:
    vector<bool> sieve(int n){
        vector<bool> prime(n+1,true);
        for(int p = 2; p*p <= n; p++){
            if(prime[p]){
                for(int i = p*p; i <= n; i+=p){
                    prime[i] = false;
                }
            }
        }
        return prime;
    }
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> prime = sieve(right);
        prime[1] = false; 
        int ans = 0;
        for(int i = left; i <= right; i++){
            int cnt = 0;
            bitset<32>x(i);
            string s = x.to_string();
            for(int j = 0; j < 32; j++){
                if(s[j] == '1') cnt++;
            }
            cout << s << "\n";
            if(prime[cnt]) ans++;
        }
        return ans;
    }
};