class Solution {
private:
    static inline int digSum(int n){
        int sum{0};
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i{0}; i < n; ++i){
            if(digSum(nums[i]) == i) return i;
        }
        return -1;
    }
};