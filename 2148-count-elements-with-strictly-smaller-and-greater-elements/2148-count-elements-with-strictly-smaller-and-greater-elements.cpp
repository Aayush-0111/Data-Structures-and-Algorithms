class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        for(int i : nums){
            if(i == maxi || i == mini) cnt++;
        }
        return (maxi == mini) ? 0 : n - cnt;
    }
};