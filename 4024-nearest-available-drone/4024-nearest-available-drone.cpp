class Solution {
private:
    static inline int manhat(int x1, int x2, int y1, int y2){
        return abs(x1-y1) + abs(x2-y2);
    }
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n{(int)drones.size()}, mini{INT_MAX}, ans{-1};
        for(int i{0}; i < n; ++i){
            int x1{drones[i][0]}, x2{drones[i][1]}, y1{target[0]}, y2{target[1]}, range{drones[i][2]};
            int dist{manhat(x1,x2,y1,y2)};
            if(dist <= range && dist < mini){
                ans = i;
                mini = dist;
            }
        }
        return ans;
    }
};