class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), maxi = 0, mini = n;
        int left[50000], right[50000], count[50000] = {0};
        fill(left, left + 50000, -1);
        for(int i = 0; i < n; i++){
            if(left[nums[i]] == -1) left[nums[i]] = i;
            if(++count[nums[i]] > maxi){
                maxi = count[nums[i]];
                mini = i - left[nums[i]] + 1;
            }else if(count[nums[i]] == maxi){
                mini = min(mini,i-left[nums[i]]+1);
            } 
        }
        return mini;
    }
};