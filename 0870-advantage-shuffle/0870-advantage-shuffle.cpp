class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if(n == 1) return nums1;
        vector<int> ans(n);
        vector<pair<int,int>> sec;
        for(int i = 0; i < n; i++) sec.push_back({nums2[i],i});
        sort(nums1.begin(),nums1.end());
        sort(sec.begin(),sec.end());
        int l = 0, r = n-1;
        // if the largest of the nums2 is greater than largest of nums1
        // use smallest of the nums1 for it so we can use the larger elemnts for other nums2 elements
        // if the largest of nums1 is largest among nums2, we it first
        for(int i = n-1; i >= 0; i--){
            int a = sec[i].first;
            int b = sec[i].second;
            if(nums1[r] > a){
                ans[b] = nums1[r];
                r--;
            }else {
                ans[b] = nums1[l++];
            }
        }
        return ans;
    }
};