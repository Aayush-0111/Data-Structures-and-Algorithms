class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = n-1; i>= 0; i--){
            int num = nums[i];
            while(num){
                int dig = num%10;
                ans.push_back(dig);
                num /= 10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};