vector<int> candidates = {1,2,3,4,5,6,7,8,9};
const int sum = 45;
class Solution {
private:
    void solve(vector<int>& candidates, int i, int k, int n, vector<int> op, vector<vector<int>>& ans, int count, const int sum,int currSum){
        if(n == 0 && k == count){
            ans.push_back(op);
            return;
        }
        currSum += (i < 9) ? candidates[i] : 0;
        int remSum = n - currSum;
        if(i >= candidates.size() || count > k || n < 0 || remSum > sum-currSum) return;
        // include
        op.push_back(candidates[i]);
        solve(candidates,i+1,k,n-candidates[i],op,ans,count+1,sum,currSum);
        op.pop_back();
        currSum -= candidates[i];
        //exclude
        solve(candidates,i+1,k,n,op,ans,count,sum,currSum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int i = 0, count = 0, currSum = 0;
        vector<int> op;
        vector<vector<int>> ans;
        solve(candidates,i,k,n,op,ans,count,sum,currSum);
        return ans;
    }
};