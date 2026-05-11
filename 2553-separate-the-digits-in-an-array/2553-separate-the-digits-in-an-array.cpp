int tens[6] = {1,10,100,1000,10000,100000};
class Solution {
private:
    vector<int> ans;
    inline void extract(int num){
        int md = upper_bound(tens,tens+6,num) - tens - 1;
        for(int i = md; i >= 0; i--){
            auto [q,r] = div(num,tens[i]);
            ans.push_back(q);
            num = r;
        }
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        ans.reserve(n*6);
        for(int i : nums) extract(i);
        return ans;
    }
};