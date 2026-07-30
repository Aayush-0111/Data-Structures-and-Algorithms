static int frq[26] = {0};
class Solution {
public:
    int minimumPushes(string word) {
        memset(frq,0,sizeof(frq));
        for(char& c : word) ++frq[c-'a'];
        sort(frq,frq+26);
        int cnt = 0, ans = 0;
        for(int i = 25; i >= 0; i--){
            ans += frq[i]*(1 + cnt/8);
            ++cnt;
        }
        return ans;
    }
};