#define ll long long
class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        ll currS = 0, initS = 0;
        // we need to know bonus for every idx in the monsters array.
        // Boosts contains bonus for certain ranges. So to determine the 
        // bonus for entire monsters, we will use difference array concept.
        vector<ll> bonus(n+1,0);
        for(auto& boost : boosts){
            bonus[boost[0]] += boost[2];
            bonus[boost[1]+1] -= boost[2];
        }
        for(int i = 1; i <= n; i++) bonus[i] += bonus[i-1];

        ll drag = 0;
        for(int i = 0; i < n; i++){
            ll diff = currS - monsters[i] + bonus[i];
            if(diff < 0){
                initS += abs(diff);
                initS += drag;
                currS += abs(diff);
                drag = 0;
            }
            currS -= monsters[i];
            if(currS < 0){
                drag += abs(currS);
                currS = 0;
            }
        }
        return initS;
    }
};