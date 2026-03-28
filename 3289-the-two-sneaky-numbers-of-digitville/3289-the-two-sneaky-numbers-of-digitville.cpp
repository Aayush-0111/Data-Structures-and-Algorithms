class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> frq;
        for(int i : nums){
            if(!frq.count(i)) frq[i]++;
            else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};