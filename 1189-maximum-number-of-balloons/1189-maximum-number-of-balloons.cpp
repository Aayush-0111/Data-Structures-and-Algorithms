class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size(), mini1 = n, mini2 = n;
        unordered_map<char,int> mp = {{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
        for(auto& c : text) if(mp.count(c)) mp[c]++;
        for(auto& p : mp){
            if(p.first == 'b' || p.first == 'a' || p.first == 'n') mini1 = min(mini1,p.second);
            else mini2 = min(mini2,p.second/2);
        }
        return min(mini1,mini2);
    }
};