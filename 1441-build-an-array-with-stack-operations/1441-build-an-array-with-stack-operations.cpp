class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        vector<string> ans;
        int x = 1, i = 0, m = target.size();
        while(i < m){
            s.push(x);
            ans.push_back("Push");
            if(s.top() == target[i]){
                i++;
            }else{
                if(!s.empty()){
                    s.pop();
                    ans.push_back("Pop");
                }
            }
            x++;
        }
        return ans;
    }
};