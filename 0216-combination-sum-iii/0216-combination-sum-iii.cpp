class Solution {
private:
    void solve(int i, vector<int> op, vector<vector<int>>& ans, int n, int k){
        if(n == 0 && op.size() == k){
            ans.push_back(op);
            return;
        }
        if(n < 0 || op.size() > k) return;
        for(int j = i; j <= 9; j++){
            op.push_back(j);
            solve(j+1,op,ans,n-j,k);
            op.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> op;
        vector<vector<int>> ans;
        solve(1,op,ans,n,k);
        return ans;
    }
};