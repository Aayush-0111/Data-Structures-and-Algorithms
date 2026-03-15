class Solution {
public:
    long long countCommas(long long n) {
        if(n <= 999) return 0;
        else if(n > 999 && n <= 999999) return 1LL*(n-999);
        else if(n > 999999 && n <= 999999999) return 1LL*((n-999)+(n-999999));
        else if(n > 999999999 && n <= 999999999999) return 1LL*((n-999) + (n-999999) + (n-999999999));
        else if(n > 999999999999 && n <= 999999999999999) return 1LL*((n-999) + (n-999999) + (n-999999999) + (n-999999999999));
        else return 1LL*((n-999) + (n-999999) + (n-999999999) + (n-999999999999) + 1);
    }
};