class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int differnce = 0;
        int p1 = 0, p2 = 0;
        bool pl1 = true, pl2 = false;
        for(int i = 0; i < n; i++){
            if((i+1)%6 == 0){
                if(pl1){
                    pl2 = true;
                    pl1 = false;
                }else{
                    pl1 = true;
                    pl2 = false;
                }
            }
            if(nums[i]%2 != 0){
                if(pl1){
                    pl1 = false;
                    pl2 = true;
                    p2 += nums[i];
                }else{
                    pl2 = false;
                    pl1 = true;
                    p1 += nums[i];
                }
            }else{
                if(pl1){
                    p1 += nums[i];
                }else{
                    p2 += nums[i];
                }
            }
        }
        return p1 - p2;
    }
};