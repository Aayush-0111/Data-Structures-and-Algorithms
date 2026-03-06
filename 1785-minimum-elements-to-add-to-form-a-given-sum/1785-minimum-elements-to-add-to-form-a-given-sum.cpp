class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n = nums.size();
        long long sum = 0;
        int ans = 0;
        for(int i : nums){
            sum += i;
        }
        return (abs(goal-sum) + limit - 1)/limit;
    }
};