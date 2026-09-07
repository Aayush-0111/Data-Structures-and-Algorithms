static const long long mod = 1e9+7;
static int arr[26];
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(arr,-1,sizeof(arr)); // for tracking prev occurences of chars
        vector<long long> dp(n+1,0);
        dp[0] = 1; // "" -> empty subsequnce
        for(int i{1}; i <= n; ++i){
            // skip the current char and you are left with old subsequences
            // also if you take the current char, you still have old subsequences with current char appended to it
            // just have to deal with the duplicates that it generated
            dp[i] = 2*dp[i-1]%mod;
            int prev{arr[s[i-1]-'a']};
            if(prev != -1) dp[i] -= dp[prev]; // remove the subseq made just before last occ of s[i]
            // cause current s[i] will append to those and create same subseq created by last occ of s[i] a.k.a duplicates
            dp[i] %= mod;
            arr[s[i-1]-'a'] = i-1;
        }
        // remove the "" subseq. and return
        return (dp[n]-1+mod)%mod;
    }
};