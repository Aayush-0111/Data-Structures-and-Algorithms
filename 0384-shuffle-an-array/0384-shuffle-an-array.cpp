class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> p = v;
        int n = p.size();
        for(int i = 0; i < n; i++){
            int idx = rand()%n;
            swap(p[i],p[idx]);
        }
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */