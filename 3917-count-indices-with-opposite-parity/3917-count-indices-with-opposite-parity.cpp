class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int ev = 0, odd = 0;
        vector<int> ans;
        for(int i : nums){
            if(i%2 == 0) ev++;
            else odd++;
        }
        for(int i : nums){
            if(i%2 == 0){
                ev--;
                ans.push_back(odd);
            }else{
                odd--;
                ans.push_back(ev);
            }
        }
        return ans;
    }
};