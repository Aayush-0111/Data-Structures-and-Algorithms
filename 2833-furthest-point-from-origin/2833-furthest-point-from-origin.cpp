class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0, l = 0, b = 0;
        for(char& c : moves){
            if(c == 'R') r++;
            else if(c == 'L') l++;
            else b++;
        }
        return (l == r) ? b : (abs(l-r)+b);
    }
};