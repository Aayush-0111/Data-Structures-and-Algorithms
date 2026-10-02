class Solution {
private:
    static inline bool isValid(string &s){
        int n = s.size();
        int count{0};
        for(char& c : s){
            if(c == '(') ++count;
            else{
                if(!count) return false;
                else --count;
            }
        }
        return !count;
    }
    void generate(int n, vector<string>& ans, string t){
        if(n <= 0) {
            if(isValid(t)) ans.push_back(t);
            return;
        }
        // take "("
        t.push_back('(');
        generate(n-1,ans,t);
        t.pop_back();
        // take ")"
        t.push_back(')');
        generate(n-1,ans,t);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string t{""};
        ans.reserve(pow(2,2*n));
        generate(2*n,ans,t);
        return ans;
    }
};