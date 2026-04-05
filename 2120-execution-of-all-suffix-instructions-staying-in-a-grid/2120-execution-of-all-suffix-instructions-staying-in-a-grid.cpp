class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans;
        ans.reserve(m);
        for(int i = 0; i < m; i++){
            int r = startPos[0], c = startPos[1], j = i;
            while(j < m && r < n && c < n){
                if(s[j] == 'R' && c+1 < n) c++;
                else if(s[j] == 'L' && c-1 >= 0) c--;
                else if(s[j] == 'U' && r-1 >= 0) r--;
                else if(s[j] == 'D' && r+1 < n) r++;
                else break;
                j++;
            }
            ans.push_back(j-i);
        }
        return ans;
    }
};