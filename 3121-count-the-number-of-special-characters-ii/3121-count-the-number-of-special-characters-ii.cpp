bool f1[26] = {false}, f2[26] = {false};
int flag[26] = {0};
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        for(char& c : word){
            if(isupper(c)){
                if(flag[c-'A'] == -1) continue;
                f2[c-'A'] = true;
                // uppercase comes first
                if(!f1[c-'A']){
                    flag[c-'A'] = -1;
                }else if(f1[c-'A']){
                    // uppercase comes after lowercase
                    flag[c-'A'] = 1; 
                }
            }else{
                if(flag[c-'a'] == -1) continue;
                f1[c-'a'] = true; 
                // lowercase comes after uppercase
                if(f2[c-'a']){
                    flag[c-'a'] = -1;
                }
            }
        }
        for(int& i : flag) if(i == 1) ans++;
        memset(flag,0,sizeof(flag));
        memset(f1,false,sizeof(f1));
        memset(f2,false,sizeof(f2));
        return ans;
    }
};