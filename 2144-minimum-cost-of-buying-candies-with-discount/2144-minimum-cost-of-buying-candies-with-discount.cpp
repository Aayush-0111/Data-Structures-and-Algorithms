class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() < 3) return (cost.size() == 1) ? cost[0] : cost[0]+cost[1];
        sort(cost.begin(),cost.end(),greater<int>());
        int n = cost.size(), ans = 0; 
        for(int i = 0; i < n; i++){
            if(i%3 != 2){
                ans += cost[i];
            }
        }
        return ans;
    }
};