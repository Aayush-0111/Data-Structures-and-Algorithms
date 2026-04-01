class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if((m == 1 && flowerbed[0] == 0) || n == 0) return true;
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 0){
                if(i == 0 && m > 1 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }else if(i-1 >= 0 && i+1 < m && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }else if(i == m-1 && (i-1) >= 0 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if(n == 0) return true;
        }
        return false;
    }
};