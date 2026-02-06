class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // think about which elements to keep
        // in a sorted array, mini will be at the staring and maxi at the end
        // we use two pointers and traverse the array to find the maximum length 
        // segment of array where the condition holds i.e., mini*k >= maxi
        // we expand till the right pointer reach an element strictly greater than the 
        // k*mini or till it goes out of bounds. 
        // We return the elements which are not in the segment i.e n - (j-i+1).
        int n = nums.size();
        if(n == 1) return 0;
        int i = 0, j = 1, ans = n;
        sort(nums.begin(),nums.end());
        while(i < n){
            // keep moving right untill right is invalid(cond. breaks)
            while(j < n && 1LL*nums[i]*k >= nums[j]) j++;
            ans = min(ans,n-(j-i));
            i++;
        }
        return ans;
    }
};