class Solution {
private:
    int prod(int n){
        int ans = 1;
        while(n){
            ans *= n%10;
            n /= 10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        for(int i{n}; i <= 100; ++i) if(prod(i)%t == 0) return i;
        return 1;
    }
};