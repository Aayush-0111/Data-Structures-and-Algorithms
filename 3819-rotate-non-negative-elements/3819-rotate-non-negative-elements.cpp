class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> t;
        for(int i : nums) if(i >= 0) t.push_back(i);
        int j = 0, m = t.size();
        if(t.empty()) return nums;
        k %= m;
        reverse(t.begin(),t.begin()+k);
        reverse(t.begin()+k,t.end());
        reverse(t.begin(),t.end());
        for(int i = 0; i < n && j < m; i++){
            if(nums[i] >= 0){
                nums[i] = t[j++];
            }
        }
        return nums;
    }
};