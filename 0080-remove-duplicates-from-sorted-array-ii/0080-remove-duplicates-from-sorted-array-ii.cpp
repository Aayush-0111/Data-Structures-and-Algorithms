class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        bool first{true};
        int l{0};
        for(int r{1}; r < n; ++r){
            if(nums[l] == nums[r] && first){
                first = false;
                ++l;
            }else if(nums[l] != nums[r]){
                first = true;
                ++l;
            }
            nums[l] = nums[r];
        }
        return l+1;
    }
};