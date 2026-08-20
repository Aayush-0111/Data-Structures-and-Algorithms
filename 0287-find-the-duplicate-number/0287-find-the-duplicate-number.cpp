class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // floyd's cycle detection algorithm.
        if(nums.size() == 1) return -1;
        // treating array like linked list
        int slow{nums[0]}; // current value gives the index of the next element in the array.
        int fast{nums[nums[0]]}; // same but takes two steps at once.
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};