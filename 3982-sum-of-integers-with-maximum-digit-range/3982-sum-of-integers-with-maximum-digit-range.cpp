class Solution {
private:
    int diff(int x){
        int mini = x, maxi = 0;
        while(x){
            mini = min(mini,x%10);
            maxi = max(maxi,x%10);
            x /= 10;
        }
        return maxi-mini;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, y = 0, ans = 0;
        for(int i = 0; i < n; i++){
            y = diff(nums[i]);
            if(y > maxi) {
                ans = nums[i];
            }else if(y == maxi) ans += nums[i];
            maxi = max(y,maxi);
        }
        return ans;
    }
};