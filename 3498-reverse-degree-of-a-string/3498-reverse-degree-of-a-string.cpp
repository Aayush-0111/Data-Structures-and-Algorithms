int pos[26] = {26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
class Solution {
public:
    int reverseDegree(string s) {
        int revDeg{0};
        for(int i{0}; i < s.size(); ++i) revDeg += (i+1)*pos[s[i]-'a'];
        return revDeg;
    }
};