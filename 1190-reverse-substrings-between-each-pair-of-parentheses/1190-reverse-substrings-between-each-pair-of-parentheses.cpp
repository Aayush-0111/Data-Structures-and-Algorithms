class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openPar;
        string ans = "";
        for(char& c : s){
            if(c == '(') openPar.push(ans.length());
            else if(c == ')'){
                int start = openPar.top();
                openPar.pop();
                reverse(ans.begin()+start, ans.end());
            }else ans += c;
        }
        return ans;
    }
};