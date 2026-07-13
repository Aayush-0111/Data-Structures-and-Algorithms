class Solution {
private:
    void solve(string& d, int i, string op, vector<string>& ans, string *m){
        if(i >= d.size()){
            ans.push_back(op);
            return;
        }
        int idx = d[i] - '0';
        string value = m[idx];
        for(int j = 0; j < value.size(); j++){
            op.push_back(value[j]);
            solve(d,i+1,op,ans,m);
            op.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string op = "";
        int i = 0;
        string mappings[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,i,op,ans,mappings);
        return ans;
    }
};