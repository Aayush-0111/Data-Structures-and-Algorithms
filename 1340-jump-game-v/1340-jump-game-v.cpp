class Solution {
private:
    vector<int> dp;
    int dfs(vector<int>& arr, vector<int>& dp, int i, int d){
        if(dp[i] != -1) return dp[i];
        int n = arr.size();
        // max number of idxs we can visit from curr pos. 
        int cnt = 1;
        // move left and explore
        // also, we will go one step at a time and max we can go is 'd'.
        for(int x = 1; i-x >= 0 && x <= d; x++){
            // if curr pos is valid, we explore how many places
            // we can go from there.
            // this process is repeated until we break the conditions given in question.
            if(arr[i] > arr[i-x]) cnt = max(cnt,1+dfs(arr,dp,i-x,d));
            else break;
        }
        // repeat everything above but in right direction
        for(int x = 1; i+x < n && x <= d; x++){
            if(arr[i] > arr[i+x]) cnt = max(cnt,1+dfs(arr,dp,i+x,d));
            else break; 
        }
        return dp[i] = cnt;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.resize(n,-1);
        // since we can choose any starting point
        // we'll have to check every idx and return the max value.
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,dfs(arr,dp,i,d));
        }
        return ans;
    }
};