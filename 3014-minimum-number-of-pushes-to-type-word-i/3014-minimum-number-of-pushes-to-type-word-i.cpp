class Solution {
public:
    int minimumPushes(string word) {
        if(word.size() <= 8) return (int)word.size();
        int ans = 0, n = word.size(), cnt = 1;
        while(n >= 0){
            ans += (n > 8) ? cnt*8 : n*cnt;
            n -= 8;
            ++cnt;
        }
        return ans;
    }
};