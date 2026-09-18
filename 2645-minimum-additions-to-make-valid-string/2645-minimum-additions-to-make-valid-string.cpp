class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int cnt{0};
        for(int i{0}; i < n; ++i){
            if(word[i] == 'a'){
                if(i == n-1 || (i == 0 && i == n-1)) cnt += 2;
                if(i+1 < n && word[i+1] == 'a') cnt += 2;
                else if(i+1 < n && word[i+1] == 'c') ++cnt;
            }else if(word[i] == 'b'){
                if(i == 0) ++cnt;
                if(i+1 < n && word[i+1] == 'b') cnt += 2;
                else if(i+1 < n && word[i+1] == 'a') ++cnt;
                if(i+1 == n) ++cnt;
            }else{
                if(i == 0) cnt += 2;
                if(i+1 < n && word[i+1] == 'c') cnt += 2;
                else if(i+1 < n && word[i+1] == 'b') ++cnt;
            }
        }
        return cnt;  
    }
};