class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n == 1) return 0;
        // 3-PASS ALGORITHM
        // 1th Pass : Calculate the a's to the right for each pos.
        // 2n Pass : Calculate the b's to the left for each pos.
        // 3rd Pass : Find the dividing line by adding a's and b's at each pos and finding the minimum
        // Optimal pos will contain the minimum sum of a's to right and b's to left
        vector<int> a(n,0), b(n,0);
        int cntA = 0, cntB = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++){
            b[i] = cntB;
            if(s[i] == 'b') cntB++; // current element will not be a part of count for curr pos
        }
        for(int i = n-1; i >= 0; i--){
            a[i] = cntA;
            if(s[i] == 'a') cntA++; // current element will not be a part of count for curr pos
        }
        for(int i = 0; i < n; i++){
            ans = min(ans,a[i]+b[i]);
        }
        return ans;
    }
};