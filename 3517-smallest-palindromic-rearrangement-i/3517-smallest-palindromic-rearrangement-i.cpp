class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int partition = n/2;
        sort(s.begin(),s.begin()+partition);
        for(int i = 0; i < partition; i++){
            s[n-i-1] = s[i];
        }
        return s;
    }
};