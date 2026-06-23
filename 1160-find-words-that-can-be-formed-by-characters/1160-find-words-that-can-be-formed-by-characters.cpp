class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        std::array<int,26> frq = {}, occ = {};
        for(char& c : chars) frq[c-'a']++;
        occ = frq;
        int ans = 0;
        for(auto& s : words){
            int count = 0;
            for(auto& c : s) {
                occ[c-'a']--;
                count++;
                if(occ[c-'a'] < 0) {
                    count = 0;
                    break;
                }
            }
            ans += count;
            occ = frq;
        }
        return ans;
    }
};