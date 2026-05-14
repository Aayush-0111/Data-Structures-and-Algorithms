class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size(), maxi = *max_element(nums.begin(),nums.end());
        if(n != maxi+1) return false;
        bool maxiTwice = false;
        vector<int> frq(n+1,0);
        for(int& i : nums){
            frq[i]++;
            if(i == maxi){
                if(frq[i] == 2) maxiTwice = true;
                else if(frq[i] > 2) return false;
            }else if(frq[i] > 1) return false;
        }
        return maxiTwice;
    }
};