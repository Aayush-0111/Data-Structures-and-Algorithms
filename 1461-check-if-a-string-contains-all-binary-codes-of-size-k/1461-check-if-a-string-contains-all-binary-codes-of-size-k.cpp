class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        int count = 0;
        int total = 1 << k; // 2^k 
        int mask = 0;
        int full_mask = total - 1; // k set bits
        vector<uint8_t> seen(1 << k, 0);
        for(int i = 0; i < n; ++i){
            mask = ((mask << 1) & full_mask) | (s[i]-'0');
            if(i >= k-1 && !seen[mask]){
                seen[mask] = 1;
                if(++count == total) return true;
                if (s.size() < (1ULL << k) + k - 1) return false;
            }
        }
        return false; 
    }
};