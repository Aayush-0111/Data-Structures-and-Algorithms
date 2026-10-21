class Solution {
private:
    static inline bool isSorted(string& s){
        for(int i{1}; i < s.size(); ++i){
            if(s[i] < s[i-1]) return false;
        }
        return true;
    }
public:
    int minOperations(string s) {
        if(isSorted(s)) return 0;
        else if(s.size() == 2) return -1;
        int n = s.size();
        char mx{'a'}, mn{'z'};
        for(char& c : s){
            mn = min(mn,c);
            mx = max(mx,c);
        }
        if(s[0] == mn || s[n-1] == mx) return 1;
        for(int i{1}; i < n-1; ++i) if(s[i] == mn || s[i] == mx) return 2;
        return 3;
    }
};