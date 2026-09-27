class Solution {
public:
    string reverseParentheses(string s) {
        // Wormhole/Teleportation technique
        int n = s.size();
        stack<int> open;
        vector<int> holes(n);
        // first pass: pair up the idx of opening brackets with corresponding closing brackets
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
        // Second pass: If you encounter a opening bracket, teleport the current idx to the closing bracket
        // and move backwards and accumulate the characters till you encounter a closing bracket.
        // then you teleport again to next corresonding opening bracket.
        // In the meantime, you accumulate the non-paranthesis characters in your answer, essentially reversing the sub-strings within braces
        // this avoids using reverse again and again.
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