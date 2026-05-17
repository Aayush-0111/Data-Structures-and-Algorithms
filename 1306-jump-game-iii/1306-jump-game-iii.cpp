class Solution {
private:
    bool bfs(vector<int>& arr, vector<bool>& visited, int node){
        int n = arr.size();
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(arr[front] == 0) return true;
            int l = (front-arr[front] >= 0) ? front-arr[front] : -1;
            int r = (front+arr[front] <= n-1) ? front+arr[front] : -1;
            if(l != -1 && !visited[l]){
                visited[l] = true;
                q.push(l);
            }
            if(r != -1 && !visited[r]){
                visited[r] = true;
                q.push(r);
            }
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // every element(i)
        //   /       |
        //  i-1      i+1
        // create visited
        vector<bool> visited(n,false);
        return bfs(arr,visited,start);
    }
};