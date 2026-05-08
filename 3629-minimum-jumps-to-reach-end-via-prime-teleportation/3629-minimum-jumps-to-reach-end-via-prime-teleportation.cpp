const int m = 1e6;
vector<int> sieve[m+1];
bool initialized = [](){
    for(int p = 2; p <= m; p++){
        if(sieve[p].empty()){
            for(int i = p; i <= m; i+=p){
                sieve[i].push_back(p);
            }
        }
    }
    return true;
}();
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> adj;
        for(int i = 0; i < n; i++){
            for(auto p : sieve[nums[i]]){
                adj[p].push_back(i);
            }
        }
        int ans = 0;
        vector<bool> visited(n,false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int m = q.size();
            while(m--){
                int front = q.front();
                q.pop();
                if(front == n-1) return ans;
                // check left
                if(front > 0 && !visited[front-1]){
                    visited[front-1] = true;
                    q.push(front-1);
                }
                // check right
                if(front < n-1 && !visited[front+1]){
                    visited[front+1] = true;
                    q.push(front+1);
                }
                // teleport
                if(sieve[nums[front]].size() == 1){
                    int p = nums[front];
                    for(int j : adj[p]){
                        if(!visited[j]){
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                        // just so we dont revisit prime again
                    adj[p].clear();
                }
            }
            ans++;
        }
        return ans;
    }
};