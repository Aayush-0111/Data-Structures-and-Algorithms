class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = asteroids.size();
        long long newMass = mass;
        for(int i = 0; i < n; i++){
            if(newMass < asteroids[i]){
                pq.push(asteroids[i]);
            }else{
                newMass += asteroids[i];
            }
        }
        while(!pq.empty()){
            if(pq.top() > newMass) return false;
            else {
                newMass += pq.top();
                pq.pop();
            }
        }
        return true;
    }
};