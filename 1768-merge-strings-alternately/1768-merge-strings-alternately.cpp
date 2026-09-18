class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i{0}, j{0};
        int n = word1.size(), m = word2.size();
        string merged{""};
        while(i < n && j < m){
            merged += word1[i++];
            merged += word2[j++];
        }
        while(i < n) merged += word1[i++];
        while(j < m) merged += word2[j++];
        return merged;
    }
};