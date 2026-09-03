class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = *min_element(nums1.begin(),nums1.end());
        if(mini%2 != 0) return true;
        bool flag{true};
        for(int& i : nums1){
            if(i%2 != 0){
                flag = false;
                break;
            }
        }
        return flag;
    }
};