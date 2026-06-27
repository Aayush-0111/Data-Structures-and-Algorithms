class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<long long,int> frq;
        for(int& i : nums) frq[i]++;
        if(frq.count(1)){
            ans = (frq[1]%2 != 0) ? frq[1] : max(frq[1]-1,1);
        }
        for(auto& [i,j] : frq){
            if(i == 1) continue;
            long long x = i;
            int len = 0;
            while(frq.count(x) && frq[x] >= 2){
                len += 2;
                if(x > 1e9) break;
                x *= x;
            } 
            if(frq.count(x)) ++len;
            else --len;
            ans = max(ans,len);
        }
        return ans;
    }
};