class Solution {
private:
    long long nonPos(vector<int>& nums, int k){
        long long x = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            x += (nums[i] + k - 1)/k; 
        }
        return x;
    }
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int s = 1, e = max(n,*max_element(nums.begin(),nums.end()));
        while(s <= e){
            int k = s + (e-s)/2;
            if(k <= ans){
                if(nonPos(nums,k) <= 1LL*k*k){
                    ans = min(ans,k);
                    e = k-1;
                }else{
                    s = k+1;
                }
            }
        }
        return ans;
    }
};