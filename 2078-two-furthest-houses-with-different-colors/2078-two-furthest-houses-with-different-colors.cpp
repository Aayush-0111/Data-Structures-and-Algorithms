class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), c0 = colors[0], cn = colors[n-1], lmax = 0, rmax = 0;
        for(int i = 0; i < n; i++){
            int c = colors[i];
            lmax += (-((c0 != c) & (i > lmax))) & (i-lmax);
            rmax += (-((cn != c) & (i > rmax))) & (n-1-i-rmax);
        }
        return max(lmax,rmax);
    }
};