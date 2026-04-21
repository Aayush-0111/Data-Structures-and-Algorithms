class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), maxi = 0, mini = n;
        unordered_map<int,tuple<int,int,int>> mp;
        for(int i = 0; i < n; i++){
            if(!mp.count(nums[i])){
                get<1>(mp[nums[i]]) = i;
            }
            get<0>(mp[nums[i]])++;
            get<2>(mp[nums[i]]) = i;
            maxi = max(maxi,get<0>(mp[nums[i]]));
        }
        vector<int> mps;
        for(auto& [m,p] : mp){
            if(get<0>(p) == maxi){
                int s = get<1>(p), e = get<2>(p);
                mini = min(mini,e-s+1);
            }
        }
        return mini;
    }
};