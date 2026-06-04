class Solution {
private:
    int MaholWavy(int x){
        if(x <= 99) return 0;
        int w = 0, prev =x%10;
        x /= 10;
        while(x >= 10){
            if((prev < x%10 && x%10 > (x/10)%10)||(prev > x%10 && x%10 < (x/10)%10)) w++;
            prev = x%10;
            x /= 10;
        }
        return w;
    }
public:
    int totalWaviness(int num1, int num2) {
        int wavy = 0;
        for(int i = num1; i <= num2; i++){
            wavy += MaholWavy(i);
        }
        return wavy;
    }
};