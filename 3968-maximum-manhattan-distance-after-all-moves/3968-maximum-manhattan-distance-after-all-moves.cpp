class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, blnk = 0;
        for(auto& c : moves){
            if(c == 'L') x--;
            else if(c == 'R') x++;
            else if(c == 'U') y++;
            else if(c == 'D') y--;
            else blnk++;
        }
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