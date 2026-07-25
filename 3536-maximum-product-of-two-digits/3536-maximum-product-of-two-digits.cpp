class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0, maxi2 = 0;
        while(n){
            if(maxi1 >= n%10){
                maxi2 = max(maxi2,n%10);
            }else{
                maxi2 = maxi1;
                maxi1 = n%10;
            }
            n /= 10;
        }
        return maxi1*maxi2;
    }
};