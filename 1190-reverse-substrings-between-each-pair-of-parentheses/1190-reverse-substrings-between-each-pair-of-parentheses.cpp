class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> open;
        vector<int> holes(n);
        for(int i{0}; i < n; ++i){
            char c{s[i]};
            if(c == '(') open.push(i);
            else if(c == ')'){
                int j{open.top()};
                holes[i] = j;
                holes[j] = i;
                open.pop();
            }
        }
        string ans;
        for(int i{0}, dir{1}; i < n; i+=dir){
            char c{s[i]};
            if(c == '(' || c == ')'){
                i = holes[i];
                dir = -dir;
            }else ans += c;
        }
        return ans;
    }
};