class Solution {
    vector<bool> visited;
private:
    bool bfs(string& s, vector<bool>& visited, int node, int minJump, int maxJump){
        int n = s.size();
        queue<int> q;
        visited[node] = true;
        q.push(node);
        int farthest = -1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(f == n-1) return true;
            // we are using farthest so that we don't revisit a range
            // farhtest makes sure how far we have scanned the array
            // visited is essentially doing the same thing but because
            // we are rechecking the overlapping ranges, time limit exceeds.
            int start = max(f+minJump,farthest+1);
            for(int j = start; j <= min(f+maxJump,n-1); j++){
                if(s[j] == '0' && !visited[j]){
                    q.push(j);
                    visited[j] = true;
                }
            }
            farthest = min(f+maxJump,n-1);
        }
        return false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        visited.resize(n,false);
        return bfs(s,visited,0,minJump,maxJump);
    }
};