class Solution {
private:
    static constexpr double eps = 1e-7;
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes = *max_element(workerTimes.begin(),workerTimes.end());
        long long s = 1, e = 1LL*maxWorkerTimes*mountainHeight*(mountainHeight + 1)/2;
        long long ans = 0;
        while(s <= e){
            long long mid = s + (e-s)/2;
            long long cnt = 0;
            for(int t : workerTimes){
                long long work = mid/t;
                long long k = (-1.0 + sqrt(1 + work*8))/2 + eps;
                cnt += k;
            }
            if(cnt >= mountainHeight){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};