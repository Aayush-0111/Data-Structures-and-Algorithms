class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int digit_fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        int cnt1[10] = {0};
        vector<int> digits;
        int p = n;
        while(p){
            int x = p%10;
            cnt1[x]++;
            digits.push_back(digit_fact[x]);
            p /= 10;
        }
        long long sum = accumulate(digits.begin(),digits.end(),0LL);
        int cnt2[10] = {0};
        while(sum){
            int x = sum%10;
            cnt2[x]++;
            sum /= 10;
        }
        for(int i = 0; i < 10; i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};