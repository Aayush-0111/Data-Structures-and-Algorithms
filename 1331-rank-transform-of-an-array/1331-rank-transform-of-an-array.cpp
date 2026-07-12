class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int,int> mp;
        sort(temp.begin(),temp.end());
        int rnk = 1;
        for(int& i : temp) if(!mp.count(i)) mp[i] = rnk++;
        for(int& i : arr) i = mp[i];
        return arr;
    }
};