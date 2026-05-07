class Solution {
public:
    int binaryGap(int n) {
        int l = -1, maxi = 0;
        for(int i = 0; i < 32; i++){
            if((n >> i) & 1 > 0 && l != -1){
                maxi = max(maxi,abs(l-i));
                l = i;
            }else if((n >> i) & 1 > 0 && l == -1) l = i;
        }
        return maxi;
    }
};