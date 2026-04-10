class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto& [a,b] : mp){
            if(b.size() < 3) continue;
            int x = b.size(), i = 0;
            while(i < x-2){
                int dist = abs(b[i]-b[i+1]) + abs(b[i+1]-b[i+2]) + abs(b[i+2]-b[i]);
                ans = min(ans,dist);
                i++;
            }
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};