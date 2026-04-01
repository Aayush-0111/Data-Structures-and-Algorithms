class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        int maxi = *max_element(asteroids.begin(),asteroids.end());
        int mini = *min_element(asteroids.begin(),asteroids.end());
        long long newMass = mass;
        vector<int> frq(maxi+1,0);
        for(int i = 0; i < n; i++){
            if(newMass >= asteroids[i]) newMass += asteroids[i];
            else frq[asteroids[i]]++;
        }
        for(int i = mini; i <= maxi; i++){
            if(frq[i] != 0 && newMass >= i){
                newMass += 1LL*frq[i]*i;
            }else {
                if(frq[i] == 0) continue;
                else return false;
            }
        }
        return true;
    }
};