class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size(), cnt = 0, cntB = 0;
        for(char &c : moves){
            if(c == 'R') cnt++;
            else if(c == 'L') cnt--;
            else cntB++;
        }
        return abs(cnt) + cntB; 
    }
};