static int frq[51];
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        memset(frq,0,sizeof(frq));
        int n{(int)nums.size()}, ans{-1};
        for(int& i : nums) ++frq[i];
        if(k == 1){
            for(int i{50}; i >= 0; --i) if(frq[i] == 1) return i;
        }else if(k == n){
            return *max_element(nums.begin(),nums.end());
        }else{
            if(frq[nums[0]] == 1 && frq[nums[n-1]] != 1) return nums[0];
            else if(frq[nums[0]] != 1 && frq[nums[n-1]] == 1) return nums[n-1];
            else if(frq[nums[0]] == 1 && frq[nums[n-1]] == 1) return max(nums[0],nums[n-1]);
        }
        return -1;
    }
};