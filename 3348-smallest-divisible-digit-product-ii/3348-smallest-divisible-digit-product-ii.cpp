class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for(int i{2}; i <= 9; ++i){
            while(temp%i == 0) temp /= i;
        }
        if(temp > 1) return "-1";
        int n = num.size();
        // build rem array
        vector<long long> rem(n+1);
        rem[0] = t;
        int pos = n-1;
        for(int i{0}; i < n; ++i){
            // encounter '0', record positon and break.
            if(num[i] == '0'){
                pos = i;
                break;
            }
            rem[i+1] = rem[i]/gcd(rem[i],num[i]-'0');
        }
        // rem[n] = 1 indicates all the factors of t have been satified and num is divisible by t.
        if(rem[n] == 1) return num;
        for(int i{pos}; i >= 0; --i){
            // increment 0 to 1,2,3...9 till we find the valid suffix.
            while(++num[i] <= '9'){
                // tnow represents how much the suffix needs to contribute for the entire num
                // to be divisible by t.
                long long tnow = rem[i]/gcd(rem[i],num[i]-'0');
                // now we go to the rightmost digit and start building num
                // we take the largest factor(that divs t) we can find, can assing it to that pos.
                // that way all the larger fators remaing at the rightmost end and we can build the
                // smallest suffix.
                int k{9};
                for(int j{n-1}; j > i; --j){
                    while(tnow%k) --k; // largest dig(b/w 1-9) which is div by tnow.
                    num[j] = '0' + k;
                    tnow /= k;
                }
                if(tnow == 1) return num; // same logic as rem[n].
            }
        }
        // by now if we are not able to find the ans, there is no possible ans of the same len as num.
        // so we will be incrementing the len.
        // To do this optimally, we will extract the factors from the t and then use them to create ans.
        // If the len of number formed by extracting factors is less than num, we will prepend it with '1'
        // cause 1 is the only number that will not affect our logic.
        // ex: t = 72 -> 9x8 so we have {9,8} -> and let say n = 5, so we have exhausted the possiblitiy
        // of finding ans of len 5 so minimum len of ans is 6. And we have two factors, rest we prepend 1s
        // so final ans = 111189 -> to check the logic, 1x1x1x1x8x9 % 72 = 0 -> hence verified.
        string ans;
        for(int i{9}; i > 1; --i){
            while(t%i == 0){
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n+1 - (int)ans.length(), 0), '1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};