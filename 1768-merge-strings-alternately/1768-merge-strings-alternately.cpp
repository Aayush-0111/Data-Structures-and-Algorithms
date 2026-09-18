class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        word1.resize(n+m);
        int i{n-1}, j{m-1}, k{n+m-1};
        // if word2 have more character than word1
        while(j >= n) word1[k--] = word2[j--];
        while(i >= 0 && j >= 0){
            if(i == j){
                word1[k--] = word2[j--];
                word1[k--] = word1[i--];
            }else word1[k--] = word1[i--];
        }
        return word1; 
    }
};