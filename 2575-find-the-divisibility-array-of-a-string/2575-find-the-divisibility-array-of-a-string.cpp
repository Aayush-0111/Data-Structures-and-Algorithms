#define ll long long
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n,0);
        ll pre = 0;
        for(int i = 0; i < n; i++){
            pre = (pre*10%m + (word[i]-'0'))%m;
            ans[i] = (pre == 0);
        }
        return ans;
    }
};