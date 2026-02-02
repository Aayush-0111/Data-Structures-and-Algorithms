class Solution {
public:
    int residuePrefixes(string s) {
        int count = 0, uniq = 0, len = 0;
        vector<bool> v(26,false);
        for(char c : s){
            len++;
            if(!v[c - 'a']){
                v[c - 'a'] = true;
                uniq++;
            }
            if(uniq == len%3) count++;
        }
        return count;
    }
};