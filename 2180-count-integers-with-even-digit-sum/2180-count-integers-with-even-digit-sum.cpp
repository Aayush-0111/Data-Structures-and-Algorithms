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
        int sum = digSum(num);
        return (sum % 2 == 0) ? num/2 : (num-1)/2;
    }
};