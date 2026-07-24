class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int upper = 1;
        while(upper <= maxi) upper <<= 1;
        bool *one = new bool[upper](), *two = new bool[upper](), *thr = new bool[upper]();
        for(int& i : nums){
            one[i] = true;
            for(int j = 0; j < upper; j++){
                if(one[j]) two[i^j] = true;
            }
        }
        for(int& i : nums){
            for(int j = 0; j < upper; j++){
                if(two[j]) thr[i^j] = true;
            }
        }
        int ans = 0;
        for(int i = 0; i < upper; i++) if(thr[i]) ++ans;
        return ans;
    }
};