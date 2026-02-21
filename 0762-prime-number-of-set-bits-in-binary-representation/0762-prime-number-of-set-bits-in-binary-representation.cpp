class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // maximum bits required to represent 10^6 is 20 (1000000)
        // maximum number of set bits that can be prime is 19.
        int prime[8] = {2,3,5,7,11,13,17,19}; 
        int ans = 0;
        for(int i = left; i <= right; i++){
            int cnt = 0;
            bitset<32>x(i);
            string s = x.to_string();
            for(int j = 0; j < 32; j++){
                if(s[j] == '1') cnt++;
            }
            for(int j = 0; j < 8; j++){
                if(prime[j] == cnt){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};