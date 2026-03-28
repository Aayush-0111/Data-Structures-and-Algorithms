class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        while((int)ans.size() < n){
            vector<int> temp;
            for(int i : ans) if(i*2 - 1 <= n) temp.push_back(2*i-1);
            for(int i : ans) if(i*2 <= n) temp.push_back(2*i);
            ans = temp;
        }
        return ans;
    }
};