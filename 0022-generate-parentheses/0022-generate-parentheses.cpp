class Solution {
private:
    void generate(int o, int c, vector<string>& ans, string& t){
        if(o == 0 && c == 0){
            ans.push_back(t);
            return;
        }
        if(o > 0){
            t.push_back('(');
            generate(o-1,c,ans,t);
            t.pop_back();
        }
        if(c > o){
            t.push_back(')');
            generate(o,c-1,ans,t);
            t.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string t{""};
        generate(n,n,ans,t);
        return ans;
    }
};