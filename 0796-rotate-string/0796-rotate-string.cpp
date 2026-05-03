class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return true;
        int n = s.size(), m = goal.size();
        if(n != m) return false;
        string t = s+s;
        auto it = t.find(goal);
        return (it != std::string::npos) ? true : false;
    }
};