class Solution {
private:
    void solve(int n, int k, int i, vector<int> op, vector<vector<int>>& ans){
        if(op.size() == k){
            ans.push_back(op);
            return;
        }
        for(int j{i}; j <= n; j++){
            op.push_back(j);
            solve(n,k,j+1,op,ans);
            op.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i =  1;
        vector<int> op;
        solve(n,k,i,op,ans);
        return ans;
    }
};