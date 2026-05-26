class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        bool up = false, rest = false;
        if(word[0] >= 'A' && word[0] <= 'Z') up = true; 
        if(word[1] >= 'A' && word[1] <= 'Z'){
            if(!up) return false;
            rest = true;
        }
        for(int i = 2; i < n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(up && !rest || !up) return false;
            }
            else{
                if(rest) return false;
            }
        }
        return true;
    }
};