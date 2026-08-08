class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size(), j = m-1, modi = 0;
        vector<int> suff(m,-1);
        for(int i{n-1}; i >= 0 && j >= 0; --i){
            if(word1[i] == word2[j]){
                suff[j] = i;
                --j;
            }
        }
        for(int i:suff) cout << i << " ";
        vector<int> ans;
        j = 0;
        for(int i{0}; i < n; ++i){
            if(j == m) break;
            if(word1[i] == word2[j]){
                ans.push_back(i);
                ++j;
            }else{
                if(!modi && j < m-1 && suff[j+1] > i){
                    modi = 1;
                    ans.push_back(i);
                    ++j;
                }else if(!modi && j == m-1){
                    ans.push_back(i);
                    break;
                }
            } 
        }
        return (ans.size() == m) ? ans : vector<int>();
    }
};