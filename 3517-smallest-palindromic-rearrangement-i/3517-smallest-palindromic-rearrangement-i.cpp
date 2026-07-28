class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int frq[26] = {0};
        // count frequencies of characters in one half.
        for(int i = 0; i < n/2; i++) ++frq[s[i]-'a'];
        int l = 0, r = n-1;
        // put lexicographically smallest characters in both halfs to obtain
        // lexicographically smallest palindromic permutation.
        for(int i = 0; i < 26; i++){
            while(frq[i] > 0){
                char c = i + 'a';
                s[l++] = c;
                s[r--] = c;
                --frq[i];
            }
        }
        return s;
    }
};