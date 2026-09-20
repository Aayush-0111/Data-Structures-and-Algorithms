class Solution {
public:
    int reverseDegree(string s) {
        int revDeg{0};
        for(int i{0}; i < s.size(); ++i) revDeg += (i+1)*(26-(s[i]-'a'));
        return revDeg;
    }
};