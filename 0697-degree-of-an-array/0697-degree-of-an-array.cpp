class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), maxi = 0, mini = n;
        int left[50000], right[50000], count[50000] = {0};
        fill(left, left + 50000, -1);
        fill(right,right + 50000, -1);
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
            if(left[nums[i]] == -1) left[nums[i]] = i;
            maxi = max(maxi,count[nums[i]]);
        }
        for(int i = n-1; i >= 0; i--){
            if(right[nums[i]] == -1){
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