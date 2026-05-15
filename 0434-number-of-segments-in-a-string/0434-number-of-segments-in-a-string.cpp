class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int count = 0;
        string t = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == ' '){
                count += (!t.empty()) ? 1 : 0;
                t = "";
            }else{
                t += s[i];
            }
        }
        if(!t.empty()) count++;
        return count;
    }
};