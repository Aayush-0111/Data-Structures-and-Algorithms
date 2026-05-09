class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans = {0,0};
        for(auto& c : events){
            if(ans[1] == 10) return ans;
            else if(c == "W") ans[1]++;
            else if(c == "WD" || c == "NB") ans[0]++;
            else {
                ans[0] += c[0] - '0';
            }
        }
        return ans;
    }
};