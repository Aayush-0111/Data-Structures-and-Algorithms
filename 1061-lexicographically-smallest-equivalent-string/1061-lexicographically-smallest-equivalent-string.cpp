class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(), m = baseStr.size();
        string ans = "";
        unordered_map<char,set<char>> mp;
        for(char c = 'a'; c <= 'z'; c++){
            mp[c].insert(c);
        }
        for(int i = 0; i < n; i++){
            char a = s1[i], b = s2[i];
            auto merged = mp[a];
            merged.insert(mp[b].begin(),mp[b].end());
            for(char c : merged){
                mp[c] = merged;
            }
        }
        for(char& c : baseStr){
            ans += *mp[c].begin();
        }
        return ans;
    }
};