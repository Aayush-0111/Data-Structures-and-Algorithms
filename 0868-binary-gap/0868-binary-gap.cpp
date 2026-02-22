class Solution {
public:
    int binaryGap(int n) {
        int l = -1, maxi = 0;
        for(int i = 0; i < 32; i++){
            // check whether current bit is 1
            if((n >> i) & 1 > 0){
                if(l != -1){
                    maxi = max(maxi,i-l);
                }
                l = i;
            }
        }
        return maxi;
    }
};