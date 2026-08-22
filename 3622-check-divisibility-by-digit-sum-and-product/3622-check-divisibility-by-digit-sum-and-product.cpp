class Solution {
private:
    static inline int digSum(int n){
        int sum{0};
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    static inline int digProd(int n){
        int prod{1};
        while(n){
            if(n%10 == 0) return 0;
            prod *= n%10;
            n /= 10;
        }
        return prod;
    }
public:
    bool checkDivisibility(int n) {
        int total = digSum(n) + digProd(n);
        return !(n%total);
    }
};