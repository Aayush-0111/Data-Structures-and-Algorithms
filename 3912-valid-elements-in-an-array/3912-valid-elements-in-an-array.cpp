class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size(), ml = nums[0], mr = nums[n-1], last = 0;
        if(n == 1) return nums;
        vector<bool> inc(n,false);
        vector<int> ans, t;
        ans.push_back(nums[0]);
        t.push_back(nums[n-1]);
        inc[n-1] = true; inc[0] = true;
        for(int i = 1; i < n; i++){
            if(nums[i] > ml && !inc[i]){
                ans.push_back(nums[i]);
                ml = nums[i];
                inc[i] = true;
                last = i;
            }
        }
        for(int i = n-2; i > last; i--){
            if(nums[i] > mr && !inc[i]){
                t.push_back(nums[i]);
                mr = nums[i];
                inc[i] = true;
            }
        }
        if(!t.empty()){
            int j = t.size()-1;
            while(j >= 0){
                ans.push_back(t[j--]);
            }
        }
        return ans;
    }
};