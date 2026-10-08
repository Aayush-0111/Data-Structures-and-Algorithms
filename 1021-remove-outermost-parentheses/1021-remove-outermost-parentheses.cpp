class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        vector<int> left;
        vector<int> right;
        int cnt1{0};
        for(int i{0}; i < n; ++i){
            char c{s[i]};
            if(c == '('){
                left.push_back(i);
                ++cnt1;
            }
            else{
                if(cnt1 == 1) right.push_back(i);
                else left.pop_back();
                --cnt1;
            }
        }
        string ans{""};
        int j{0}, k{0};
        for(int i{0}; i < n; ++i){
            if(j < left.size() && i == left[j]) ++j;
            else if(k < right.size() && i == right[k]) ++k;
            else ans += s[i];
        }
        return ans;
    }
};