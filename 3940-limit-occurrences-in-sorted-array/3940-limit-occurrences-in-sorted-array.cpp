class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size(), idx = 0;
        for(int i = 0; i < n; i++){
            if(idx < k || nums[i] != nums[idx-k]){
                nums[idx++] = nums[i];
            }
        }
        nums.resize(idx);
        return nums;
    }
};