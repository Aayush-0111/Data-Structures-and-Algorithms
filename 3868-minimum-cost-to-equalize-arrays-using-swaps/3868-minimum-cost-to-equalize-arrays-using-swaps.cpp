class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> st;
        bool flag = true;
        unordered_map<int,int> frq,cnt1,cnt2;
        for(int i = 0; i < n; i++){
            st.insert(nums1[i]);
            cnt1[nums1[i]]++;
            cnt2[nums2[i]]++;
            frq[nums1[i]]++;
            frq[nums2[i]]++;
            if(nums1[i] != nums2[i]) flag = false;
        }
        if(flag) return 0;
        for(auto& p : frq){
            if(p.second%2 != 0) return -1;
        }
        int cost = 0;
        for(auto i : st){
            cost += ((cnt1[i] - frq[i]/2 > 0) ? cnt1[i]-frq[i]/2 : 0);
        }
        return cost;
    }
};