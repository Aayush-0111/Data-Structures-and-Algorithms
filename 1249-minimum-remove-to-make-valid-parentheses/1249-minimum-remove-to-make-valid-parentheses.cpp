class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int> idxs;
        int cnt{0}, k{0};
        for(char& c : s){
            if(c == '(') {
                ++cnt;
                idxs.push_back(k);
            }
            else if(c == ')'){
                if(!cnt) idxs.push_back(k);
                else{
                    --cnt;
                    idxs.pop_back();
                }
            }
            ++k;
        }
        if(idxs.empty()) return s;
        string ans{""};
        int j{0};
        for(int i{0}; i < n; ++i){
            if(j < idxs.size() && i == idxs[j]){
                ++j;
            }else ans += s[i];
        }
        return ans;
    }
};