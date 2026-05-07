class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> po2;
        long long x = 1;
        while(x < 1e9){
            po2.push_back((int)x);
            x *= 2;
        }
        for(int i : po2){
            if(i == n) return true;
        }
        int m = po2.size(), y = 1;
        vector<vector<int>> dig(m,vector<int>(10,0));
        dig[0][1]++;
        for(int i = 1; i < m; i++){
            int x = po2[y++];
            while(x){
                int j = x%10;
                dig[i][j]++;
                x /= 10;
            }
        }
        vector<int> frq(10,0);
        int z = n;
        while(z){
            int j = z%10;
            frq[j]++;
            z /= 10;
        }
        for(int i = 0; i < m; i++){
            bool flag = true;
            for(int j = 0; j < 10; j++){
                if(frq[j] != dig[i][j]) flag = false;
            }
            if(flag) return true;
        }
        return false;
    }
};