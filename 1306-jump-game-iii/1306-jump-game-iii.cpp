class Solution {
private:
    void adjList(vector<vector<int>>& adj, vector<int>& nums){
        int n = adj.size();
        for(int i = 0; i < n; i++){
            // left neighbour
            adj[i][0] = (i-nums[i] >= 0) ? i-nums[i] : -1; 
            // right neighbour
            adj[i][1] = (i+nums[i] < n) ? i+nums[i] : -1;
        }
    }
    bool bfs(vector<vector<int>>& adj, vector<int>& arr, unordered_map<int,bool>& visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(arr[front] == 0) return true;
            for(int i : adj[front]){
                if(i == -1) continue;
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> adj(n,vector<int>(2,0));
        // preparing adj list
        adjList(adj,arr);
        // every element(i)
        //   /       |
        //  i-1      i+1
        // create visited
        unordered_map<int,bool> visited;
        return bfs(adj,arr,visited,start);
    }
};