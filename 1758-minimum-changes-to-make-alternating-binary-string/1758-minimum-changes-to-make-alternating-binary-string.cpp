class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), flag = 1, ops = 0;
        for(int i = 0; i < n; i++){
            int x = s[i]-'0';
            if(x^flag) ops++;
            flag = (flag) ? 0 : 1;
        }
        return min(ops,n-ops);
    }
};