class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size(), ans = 0;
        vector<pair<int,int>> f(26,{-1,-1});
        for(int i = 0; i < n; i++){
            char c = word[i];
            // first occurence of uppercase
            if(isupper(c)){
                if(f[c-'A'].first == -1){
                    f[c-'A'].first = i;
                }
            }else{
                // last occurence of lowercase
                f[c-'a'].second = i;
            }
        }
        for(int i = 0; i < 26; i++){
            if(!(f[i].first == -1 || f[i].second == -1)){
                if(f[i].first > f[i].second) ans++;
            }
        }
        return ans;
    }
};