class Solution {
private:
    int pivot(vector<int>& nums){
        int s = 0, e = nums.size()-1;
        while(s < e){
            int mid = (s+e) >> 1;
            if(nums[mid] > nums[e]) s = mid+1;
            else if(nums[mid] < nums[e]) e = mid;
            // nums[mid] == nums[e] -> eliminate duplicates
            // even if the duplicate is minimum, still it will ensure 
            // that last duplicate(which is min) falls in the above category
            else e--;
        }
        return s;
    }
public:
    int findMin(vector<int>& nums) {
        int pvt = pivot(nums);
        return nums[pvt];
    }
};