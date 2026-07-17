vector<int> candidates = {1,2,3,4,5,6,7,8,9};
class Solution {
private:
    void solve(vector<int>& candidates, int i, int k, int n, vector<int> op, vector<vector<int>>& ans, int count){
        if(n == 0 && k == count){
            ans.push_back(op);
            return;
        }
        if(i >= candidates.size() || count > k) return;
        // include
        op.push_back(candidates[i]);
        solve(candidates,i+1,k,n-candidates[i],op,ans,count+1);
        op.pop_back();
        //exclude
        solve(candidates,i+1,k,n,op,ans,count);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int i = 0, count = 0;
        vector<int> op;
        vector<vector<int>> ans;
        solve(candidates,i,k,n,op,ans,count);
        return ans;
    }
};