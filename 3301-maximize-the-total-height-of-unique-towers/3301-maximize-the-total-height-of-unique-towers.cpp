class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        int maxi = *max_element(maximumHeight.begin(),maximumHeight.end());
        vector<bool> chk(maxi+1,false);
        sort(maximumHeight.begin(),maximumHeight.end());
        int x = maximumHeight[n-1]-1;
        long long ans = maximumHeight[n-1];
        for(int i = n-2; i >= 0; i--){
            if(x <= 0) return -1;
            ans += min(maximumHeight[i],x);
            if(x > maximumHeight[i]) x = maximumHeight[i]-1;
            else x--;
        }
        return ans;
    }
};