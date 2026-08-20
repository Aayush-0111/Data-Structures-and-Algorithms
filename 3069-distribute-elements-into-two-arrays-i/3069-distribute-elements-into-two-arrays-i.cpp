class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n{(int)nums.size()};
        vector<int> ans, arr1, arr2;
        ans.reserve(n);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i{2}; i < n; ++i){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        ans = move(arr1);
        ans.insert(ans.end(),make_move_iterator(arr2.begin()),make_move_iterator(arr2.end()));
        return ans;
    }
};