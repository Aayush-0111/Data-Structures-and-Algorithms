class Solution {
private:
    inline int digSum(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
public:
    int countEven(int num) {
        int ans = 0;
        for(int i  = 1; i <= num; i++){
            if(digSum(i)%2 == 0) ans++;
        }
        return ans;
    }
};