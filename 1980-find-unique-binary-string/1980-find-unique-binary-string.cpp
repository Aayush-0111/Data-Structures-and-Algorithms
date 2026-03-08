class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> v;
        int n = nums.size();
        unordered_map<int,int> frq;
        for(int i = 0; i < n; i++){
            int x = stoi(nums[i], nullptr, 2);
            frq[x]++;
            v.push_back(x);
        }
        int req = 0;
        for(int i = 0; i < 1000000; i++){
            if(!frq.count(i)){
                req = i;
                break;
            }
        }
        bitset<16> x(req);
        string s = x.to_string();
        return s.substr(16-n);
    }
};