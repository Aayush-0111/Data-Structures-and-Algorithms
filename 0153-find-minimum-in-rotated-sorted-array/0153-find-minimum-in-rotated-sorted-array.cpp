class Solution {
private:
    int pivot(vector<int>& nums){
        int n = nums.size();
        int s = 0, e = n-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[0] <= nums[mid]) s = mid+1;
            else e = mid;
        }
        return s;
    }
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int idx = pivot(nums);
        return min(nums[idx],nums[0]);
    }
};