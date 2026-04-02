class Solution {
public:
    int countCollisions(string directions) {
        int s = 0, r = 0, ans = 0;
        for(char c : directions){
            if(c == 'R'){
                r++;
                s = 0;
            }else if(c == 'S'){
                if(r != 0){
                    ans += r;
                    r = 0;
                }
                s++;
            }else {
                if(s != 0){
                    ans += 1;
                }else if(r != 0){
                    ans += 2;
                    r--;
                    s++;
                    if(r != 0){
                        ans += r;
                        r = 0;
                    }
                }
            }
        }
        return ans;
    }
};