static vector<int> all = [](){
    vector<int> v;
    for(int i{1}; i <= 9; i++){
        int dig{i};
        for(int j{i+1}; j <= 9; j++) v.push_back(dig = 1LL*dig*10 + j);
    }
    sort(v.begin(),v.end());
    return v;
}();

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int& i : all) if(i >= low && i <= high) ans.push_back(i);
        return ans;
    }
};