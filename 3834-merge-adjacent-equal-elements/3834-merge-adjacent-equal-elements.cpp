class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        stack<long long> s,t;
        for(int i = n-1; i >= 0; i--) s.push(nums[i]);
        while(!s.empty()){
            long long top = s.top();
            t.push(top);
            s.pop();
            while(!s.empty() && !t.empty() && s.top() == t.top()){
                long long dup = 1LL*2*s.top(); s.pop(); t.pop();
                s.push(dup);
            }
        }
        int m = t.size();
        vector<long long> ans(m,0);
        for(int i = m-1; i >= 0; i--){
            long long top = t.top(); t.pop();
            ans[i] = top;
        }
        return ans;
    }
};