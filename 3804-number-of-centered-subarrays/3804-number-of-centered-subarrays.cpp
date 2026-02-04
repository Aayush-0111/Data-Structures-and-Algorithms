class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), count = n;
        for(int i = 0; i < n-1; i++){
            unordered_set<int> st;
            st.insert(nums[i]);
            int sum = nums[i];
            for(int j = i+1; j < n; j++){
                st.insert(nums[j]);
                sum += nums[j];
                if(st.count(sum)) count++;
            }
        }
        return count;
    }
};