class Solution {
public:
    bool validDigit(int n, int x) {
        if(n == 0) return false;
        string s;
        bool flag = false;
        while(n){
            int y = n%10;
            if(y == x) flag = true;
            s.push_back(y-'0');
            n /= 10;
        }
        if(s[(int)s.size()-1] == x-'0') return false;
        return flag;
    }
};