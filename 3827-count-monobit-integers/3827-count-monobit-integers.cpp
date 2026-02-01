class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;
        long long pow = 1;
        int cnt = 0;
        while(n >= pow){
            cnt++;
            pow *= 2;
            if(n == pow-1) return cnt+1;
        }
        return cnt;
    }
};