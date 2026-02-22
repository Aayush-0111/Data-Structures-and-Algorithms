class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, difference = 0;
        bool pl1 = true;
        for(int i = 0; i < n; i++){
            // Swapping the players
            if((i+1)%6 == 0) pl1 = !pl1;
            if(nums[i]%2 != 0) pl1 = !pl1;
            // Calculating scores
            if(pl1){
                p1 += nums[i];
            }else{
                p2 += nums[i];
            }
        }
        return p1-p2;
    }
};