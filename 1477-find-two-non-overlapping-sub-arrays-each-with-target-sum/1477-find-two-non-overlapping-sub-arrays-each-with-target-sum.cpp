class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n+1,INT_MAX), suffix(n+1,INT_MAX);
        int l{0}, sum{0};
        for(int r{0}; r < n; ++r){
            sum += arr[r];
            while(l < n && sum > target){
                sum -= arr[l++];
            }
            if(sum == target){
                prefix[r+1] = min(prefix[r],r-l+1);
            }
            prefix[r+1] = min(prefix[r],prefix[r+1]);
        }
        int r{n-1};
        sum = 0;
        for(int l{n-1}; l >= 0; --l){
            sum += arr[l];
            while(l > 0 && sum > target){
                sum -= arr[r--];
            }
            if(sum == target){
                suffix[l] = min(suffix[l+1],r-l+1);
            }
            suffix[l] = min(suffix[l+1],suffix[l]);
        }
        int ans{INT_MAX};
        for(int i{1}; i < n; ++i){
            if(prefix[i] != INT_MAX && suffix[i] != INT_MAX) ans = min(ans,prefix[i]+suffix[i]); 
        }
        return ans != INT_MAX ? ans : -1;
    }
};