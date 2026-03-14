class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp(80001,0);
        int cost = 0;
        for(int &i : nums1) mp[i]++;
        for(int &i : nums2) mp[i]--;
        for(auto& p : mp){
            if(p%2 != 0) return -1;
            if(p > 0) cost += p/2;
        }
        return cost;
    }
};