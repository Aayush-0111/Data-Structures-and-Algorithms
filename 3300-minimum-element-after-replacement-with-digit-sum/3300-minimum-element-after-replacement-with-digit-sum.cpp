class Solution {
private:
    int DigSum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int& i : nums){
            mini = min(mini,DigSum(i));
        }
        return mini;
    }
};