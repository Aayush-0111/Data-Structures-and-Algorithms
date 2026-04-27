class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size(), ml = 0, mr = 0;
        vector<int> ans;
        vector<bool> inc(n,false);
        int last = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > ml){
                ans.push_back(nums[i]);
                ml = nums[i];
                inc[i] = true;
                last = i;
            }
        }
        for(int i : ans){
            cout << i << " ";
        }
        int x = ans.size();
        for(int i = n-1; i > last; i--){
            if(nums[i] > mr && !inc[i]){
                ans.push_back(nums[i]);
                mr = nums[i];
                inc[i] = true;
            }
        }
        if(x < ans.size()){
            int y = ans.size() - 1;
            while(x <= y){
                swap(ans[x++],ans[y--]);
            }
        }
        return ans;
    }
};