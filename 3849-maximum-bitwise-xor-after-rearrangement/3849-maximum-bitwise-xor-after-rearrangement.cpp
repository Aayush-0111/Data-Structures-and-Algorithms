class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        string ans = "";
        int cnt0 = 0, cnt1 = 0;
        for(char c : t){
            if(c == '1') cnt1++;
            else cnt0++;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(cnt0){
                    t[i] = '0';
                    cnt0--;
                }else{
                    t[i] = '1';
                    cnt1--;
                }
            }else{
                if(cnt1){
                    t[i] = '1';
                    cnt1--;
                }else{
                    t[i] = '0';
                    cnt0--;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if((s[i] == '0' && t[i] == '1') || (s[i] == '1' && t[i] == '0')){
                ans.push_back('1');
            }else ans.push_back('0');
        }
        return ans;
    }
};