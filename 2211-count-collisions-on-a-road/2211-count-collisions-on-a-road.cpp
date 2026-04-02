class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0, r = 0, s = 0;
        char last;
        for(char c : directions){
            if(c == 'R') {
                r++;
                s = 0;
                last = 'R';
            }else if(c == 'S'){
                if(r != 0 && last == 'R'){
                    ans += r;
                    r = 0;
                }
                last = 'S';
                s++;
            }else{
                if(r != 0 && last == 'R'){
                    ans += 2;
                    last = 'S';
                    s++;
                    r--;
                    if(r != 0){
                        ans += r;
                        r = 0;
                        continue;
                    }
                }else if(s != 0 && last == 'S'){
                    ans++;
                }
            }
        }
        return ans;
    }
};