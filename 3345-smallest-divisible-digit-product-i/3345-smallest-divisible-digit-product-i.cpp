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
        int i = n;
        while(i%10){
            if(!(prod(i)%t)) break;
            ++i;
        }
        return i;
    }
};