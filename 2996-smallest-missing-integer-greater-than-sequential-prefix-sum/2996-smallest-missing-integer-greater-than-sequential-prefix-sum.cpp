static int mp[51] = {0};
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return ++nums[0];
        int sum{0}, pre{nums[0]-1}, j{0};
        for(int i{0}; i < n; ++i){
            if(nums[i] != pre+1) break;
            ++pre;
            sum += nums[i];
            j = i;
        }
        if(j+1 == n) return sum;
        int maxi = *max_element(nums.begin(),nums.end());
        if(sum > maxi) return sum;
        memset(mp,0,sizeof(mp));
        j = 0;
        while(j < n) ++mp[nums[j++]];
        while(sum <= maxi){
            if(!mp[sum]) return sum;
            ++sum;
        }
        return sum;
    }
};