static int mod = 1e9+7;
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(),y = queries.size();
        vector<int> ans;
        ans.reserve(y);
        string t = "";
        // map indicies of t to s
        for(char& c : s) if(c != '0') t += c;
        if(t.empty()) return vector<int>(y,0);
        vector<int> idx(n+1,0);
        for(int i = 1; i <= n; i++) idx[i] = idx[i-1] + (s[i-1] != '0');
        // sum of non-zero digits
        int m = t.size(); 
        vector<int> psum(m,0);
        psum[0] = t[0]-'0';
        for(int i = 1; i < m; i++) psum[i] = (psum[i-1] + t[i]-'0');
        // calculate prefix of string
        vector<int> p(m,0);
        p[0] = t[0]-'0';
        for(int i = 1; i < m; i++) p[i] = (1LL*p[i-1]*10%mod + (t[i]-'0'))%mod;
        // calculating powers of 10
        vector<int> power(m+1,1);
        for(int i = 1; i <= m; i++){
            power[i] = 1LL*power[i-1]*10%mod;
        }
        for(auto& a : queries){
            int l = idx[a[0]], r = idx[a[1]+1]-1;
            if(l > r){
                ans.push_back(0);
                continue;
            }
            ans.push_back((l != 0) ? 1LL*(psum[r]-psum[l-1])%mod*(p[r]-1LL*p[l-1]*power[r-l+1]%mod+mod)%mod : 1LL*psum[r]*p[r]%mod);
        }
        return ans;
    }
};