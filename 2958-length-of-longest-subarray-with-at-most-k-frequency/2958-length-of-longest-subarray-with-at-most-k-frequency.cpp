class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans{0}, l{0};
        unordered_map<int,pair<vector<int>,int>> frq;
        // populate the map with positon of elements in the array.
        for(int i{n-1}; i >= 0; --i) frq[nums[i]].first.push_back(i);
        for(int r{0}; r < n; ++r){
            int x = nums[r];
            ++frq[x].second;
            if(frq[x].second > k){
                //l = frq[x].first.back() + 1; will not work cause when we
                // move l, we are not reducing the frequency of the elements
                // lying b/w old l and new l, so it might trigger the condition (>k)
                // for the elements which are not be in the window anymore.
                // ex:{1,2,2,1} here when considering last '1', count will still
                // consider the first '1' cause we have not reduced it's count.
                // so we are essentially taking the l backwards which is not possible
                // in a sliding window operation.
                l = max(l,frq[x].first.back()+1);  // kind of lazy cleanup preventing stale cleanup, making sure l does not go backwards.
                frq[x].first.pop_back();
                --frq[x].second;
            }
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};