class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0 , curr = 1, prev = 0;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }else{
                curr++;
            }
        }
        return ans + min(curr,prev);
    }
};