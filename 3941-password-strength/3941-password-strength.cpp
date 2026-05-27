bool f1[26], f2[26], f3[10];
class Solution {
private:
    bool isAlp(char& c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isNum(char& c){
        return (c >= '0' && c <= '9');
    }
public:
    int passwordStrength(string password) {
        int strength = 0;
        memset(f1,false,sizeof(f1));
        memset(f2,false,sizeof(f2));
        memset(f3,false,sizeof(f3));
        unordered_set<char> st;
        for(char& c : password){
            if(isAlp(c)){
                if(islower(c)){
                    strength += (!f1[c-'a']) ? 1 : 0;
                    f1[c-'a'] = true;
                }else{
                    strength += (!f2[c-'A']) ? 2 : 0;
                    f2[c-'A'] = true;
                }
            }else if(isNum(c)){
                strength += (!f3[c-'0']) ? 3 : 0;
                f3[c-'0'] = true;
            }else{
                strength += (!st.count(c)) ? 5 : 0;
                st.insert(c);
            }
        }
        return strength;
    }
};