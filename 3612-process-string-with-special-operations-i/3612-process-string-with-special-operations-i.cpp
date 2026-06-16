class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '*'){
                if(result.size() > 0) result.pop_back();
            }
            else if(c == '#'){
                result += result;
            }
            else if(c == '%'){
                reverse(result.begin(),result.end());
            }
            else result.push_back(c);
        }
        return result;
    }
};