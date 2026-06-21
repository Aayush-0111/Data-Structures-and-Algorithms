class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.size(), l = 0, r = 0, u = 0, d = 0, x = 0, y = 0;
        for(auto& c : moves){
            if(c == 'L') {
                l++;
                x--;
            }
            else if(c == 'R') {
                r++;
                x++;
            }
            else if(c == 'U') {
                u++;
                y++;
            }
            else if(c == 'D') {
                d++;
                y--;
            }
        }
        int blnk = n-l-r-u-d;
        if(abs(x) > abs(y)){
            if(x < 0) x -= blnk;
            else x += blnk;
        }else{
            if(y < 0) y -= blnk;
            else y += blnk;
        }
        return abs(x) + abs(y);
    }
};