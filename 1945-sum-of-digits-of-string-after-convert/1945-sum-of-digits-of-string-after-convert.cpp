class Solution {
private:
    int digSum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for(char& c : s){
            ans += digSum(c-'a'+1);
        }
        k--;
        while(k--){
            ans = digSum(ans);
        }
        return ans;
    }
};