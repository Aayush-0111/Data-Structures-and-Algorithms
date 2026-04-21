class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), maxi = 0, mini = n;
        unordered_map<int,int> left, right, count;
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
            if(!left.count(nums[i])){
                left[nums[i]] = i;
            }
            maxi = max(maxi,count[nums[i]]);
        }
        for(int i = n-1; i >= 0; i--){
            if(!right.count(nums[i])){
                right[nums[i]] = i;
            }
        }
        for(int i : nums){
            if(count[i] == maxi){
                mini = min(mini,right[i]-left[i] + 1);
            }
        }
        return mini;
    }
};