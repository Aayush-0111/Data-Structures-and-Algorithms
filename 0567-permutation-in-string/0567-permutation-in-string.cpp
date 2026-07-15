class Solution {
private:
    static inline bool eql(int *arr1, int *arr2) {
        return equal(arr1,arr1+26,arr2);
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        int frq1[26] = {0}, frq2[26] = {0};
        for(char& c : s1) ++frq1[c-'a'];
        for(int i = 0; i < n; i++) ++frq2[s2[i]-'a'];
        if(eql(frq1,frq2)) return true;
        int l = 0;
        for(int r{n}; r < m; r++){
            --frq2[s2[l++]-'a'];
            ++frq2[s2[r]-'a'];
            if(eql(frq1,frq2)) return true;
        }
        return false;
    }
};