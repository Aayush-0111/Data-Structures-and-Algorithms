class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool flag = true;
        int mini = *min_element(nums1.begin(),nums1.end());
        for(int i = 0; i < n; i++){
            if(nums1[i]%2 != 0){
                flag = false;
                break;
            }
        }
        if(!flag && mini%2 == 0) return false;
        return true;
    }
};