class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), ans = 0;
        int l = 0, r = n-1;
        while(l < n && directions[l] == 'L') l++;
        while(r >= 0 && directions[r] == 'R') r--;
        // key insight is that
        // cars which are in the middle and not stationary
        // will definitely collide
        // if they collide with a 'S', we count that car
        // or if they collide with another moving car, we are already counting both of them
        // so contributing +2(as asked in question). ex : 'R' -> 'L' and vide-versa
        for(int i = l; i <= r; i++){
            if(directions[i] != 'S') ans++;
        }
        return ans;
    }
};