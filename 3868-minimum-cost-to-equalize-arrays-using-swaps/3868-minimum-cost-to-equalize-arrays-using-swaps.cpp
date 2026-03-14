class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int cost = 0;
        for(int &i : nums1) mp[i]++;
        for(int &i : nums2) mp[i]--;
        for(auto& p : mp){
            if(abs(p.second)%2 != 0) return -1;
            if(p.second > 0) cost += p.second/2;
        }
        return cost;
    }
};