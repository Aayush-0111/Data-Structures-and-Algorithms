class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(std::ranges::is_sorted(nums.begin(), nums.end())) return 0;
        int n = nums.size();
        if(n == 2) return 1;
        int k = find(nums.begin(),nums.end(),0)-nums.begin();
        bool flag1{true}, flag2{true};
        // Increasing sorted cyclic check
        for(int i{0}; i < n; ++i){
            if(nums[(i+k)%n] != i){
                flag1 = false;
                break;
            }
        }
        // Decreasing sorted cuclic check
        for(int i{0}; i < n; ++i){
            if(nums[(k-i+n)%n] != i){
                flag2 = false;
                break;
            }
        }
        if(flag1) return min(k,n-k+2); 
        else if(flag2) return 1 + min(n-1-k,k+1);
        else return -1;
    }
};