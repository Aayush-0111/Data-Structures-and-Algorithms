#define all(x) (x).begin(), (x).end()
class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*min_element(all(nums)),*max_element(all(nums)));
    }
};