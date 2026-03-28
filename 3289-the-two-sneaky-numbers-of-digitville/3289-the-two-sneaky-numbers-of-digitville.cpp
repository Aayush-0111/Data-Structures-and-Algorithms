class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int frq[101] = {0};
        for(int i : nums){
            if(frq[i] == 0) frq[i]++;
            else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};