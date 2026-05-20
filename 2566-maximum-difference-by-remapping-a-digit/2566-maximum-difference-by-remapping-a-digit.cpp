class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), st1 = "", st2 = "";
        int n = s.size();
        char a = s[0], b = s[0];
        if(s[0] == '9'){
            int i = 0;
            while(i < n && s[i] == '9') i++;
            if(i < n) a = s[i];
        } 
        for(char& c : s){
            if(c == a) st1 += '9';
            else st1 += c;
            if(c == b) st2 += '0';
            else st2 += c; 
        }
        return stoi(st1) - stoi(st2);
    }
};