static int mod = 1e9+7;
static const vector<int> power = [](){
    vector<int> p(100001);
    p[0] = 1;
    for(int i = 1; i <= 100000; i++) p[i] = 1LL*p[i-1]*10%mod;
    return p;
}();
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), m = queries.size();
        vector<int> ans;
        ans.reserve(m);
        string t = "";
        for(char& c : s) if(c != '0') t += c;
        if(t.empty()) return vector<int>(m,0);
        vector<int> idx(n,0);
        idx[0] = (s[0] != '0');
        for(int i = 1; i < n; i++) idx[i] = idx[i-1] + (s[i] != '0');
        vector<int> psum(t.size(),0);
        psum[0] = t[0]-'0';
        for(int i = 1; i < t.size(); i++) psum[i] = psum[i-1] + t[i]-'0';
        vector<int> prefix(t.size(),0);
        prefix[0] = t[0]-'0';
        for(int i = 1; i < t.size(); i++) prefix[i] = ((1LL*prefix[i-1]*10%mod) + t[i]-'0')%mod;
        for(auto& a : queries){
            int l = (a[0] == 0) ? 0 : idx[a[0]-1], r = idx[a[1]]-1;
            if(l > r){
                ans.push_back(0);
                continue;
            }
            ans.push_back((l != 0) ? 1LL*(psum[r]-psum[l-1])*(prefix[r]-1LL*prefix[l-1]*power[r-l+1]%mod + mod)%mod : 1LL*psum[r]*prefix[r]%mod);
        }
        return ans;
    }
};