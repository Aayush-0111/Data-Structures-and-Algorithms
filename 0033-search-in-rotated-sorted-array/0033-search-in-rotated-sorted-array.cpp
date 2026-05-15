class Solution {
private:
    int pivot(vector<int>& nums){
        int n = nums.size();
        int s = 0, e = n-1;
        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]) s = mid+1;
            else e = mid;
        }
        return s;
    }
    int binarySearch(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int piv = pivot(nums);
        cout << piv << '\n';
        return (binarySearch(nums,0,piv-1,target) != -1) ? binarySearch(nums,0,piv-1,target) : binarySearch(nums,piv,n-1,target);
    }
};