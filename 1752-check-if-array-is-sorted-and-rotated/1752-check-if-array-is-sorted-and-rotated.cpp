class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int k = n;
        while(k--){
            auto t = v;
            reverse(t.begin(),t.end());
            reverse(t.begin(),t.begin()+k);
            reverse(t.begin()+k,t.end());
            if(t == nums) return true;
        }
        return false;
    }
};