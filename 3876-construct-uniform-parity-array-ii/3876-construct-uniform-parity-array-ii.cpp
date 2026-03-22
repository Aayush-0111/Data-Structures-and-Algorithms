class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size(), j = 0;
        bool flag = true;
        sort(nums1.begin(),nums1.end());
        for(int i = 1; i < n; i++){
            if(nums1[i]%2 != 0) {
                flag = false;
                continue;
            }
            if(nums1[i] - nums1[j] < 1) return false;
        }
        if(!flag && nums1[0]%2 == 0) return false;
        return true;
    }
};