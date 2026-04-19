class Solution {
private:
    int farthest(vector<int>& nums, int s, int e, int tar){
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= tar){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int tar = nums1[i];
            int idx = farthest(nums2, i, m-1, tar);
            if(idx != -1) ans = max(ans,idx-i);
        }
        return ans;
    }
};