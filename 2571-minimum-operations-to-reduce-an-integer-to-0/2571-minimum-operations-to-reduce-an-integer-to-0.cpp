class Solution {
public:
    int minOperations(int n) {
        vector<int> pow;
        for(int i = 0; (1 << i) <= 2 * n; i++){
            pow.push_back(1 << i);
        }
        int ans = 0;
        while(n > 0){
            int closest = pow[0];
            for(int& p : pow){
                if(abs(n-closest) > abs(n-p)) closest = p;
            }
            n = abs(n-closest);
            ans++;
        }
        return ans;
    }
};