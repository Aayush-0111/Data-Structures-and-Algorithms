class Solution {
private:
    vector<string> validString(int n){
        string a = "0", b = "1";
        bool parity = true;
        for(int i = 1; i < n; i++){
            if(parity){
                a.push_back('1');
                b.push_back('0');
                parity = false;
            }else{
                a.push_back('0');
                b.push_back('1');
                parity = true;
            }
        }
        return {a,b};
    }
public:
    int minFlips(string s) {
        int n = s.size();
        int ans = n, op1 = 0, op2 = 0;
        // By doubling the string,every cyclic combination can be obtained as the 
        // substring of doubled string
        string t = s+s;
        vector<string> v = validString(n);
        for(int i = 0; i < n; i++){
            if(s[i] != v[0][i]) op1++;
            if(s[i] != v[1][i]) op2++;
        }
        ans = min(op1,op2);
        int l = 0;
        for(int i = n; i < (int)t.size(); i++){
            if(t[l] != (l % 2 ? '1' : '0')) op1--;
            if(t[l] != (l % 2 ? '0' : '1')) op2--;
            if(t[i] != (i % 2 ? '1' : '0')) op1++;
            if(t[i] != (i % 2 ? '0' : '1')) op2++;
            l++;
            ans = min(ans,min(op1,op2));
        }
        return ans;
    }
};