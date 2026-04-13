class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        vector<int> t;
        for(int i = 0; i < n; i++){
            if(nums[i] == target) t.push_back(i);
        }
        int ans = INT_MAX;
        for(int i : t){
            ans = min(ans,abs(i-start));
        }
        return ans;
    }
};