class Solution {
private:
    int weight(string& s, vector<int>& weights){
        int sum = 0;
        for(auto& c : s){
            sum += weights[c-'a'];
        }
        return sum%26;
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string s;
        for(auto& x : words){
            s.push_back('z'- weight(x,weights));
        }
        return s;
    }
};