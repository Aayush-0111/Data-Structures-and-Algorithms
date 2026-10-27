class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string a,b;
        for(int i = 0; i < n-1; i++) {
            a.push_back('.');
            b.push_back('#');
        }
        a.push_back('.');
        b.push_back('.');
        ans.push_back(a);
        for(int i = 1; i < m; i++) ans.push_back(b);
        return ans;
    }
};