class Solution {
public:
    vector<string> output;
    void backTrack(string& curr, int n){
        if((int)curr.size() == n){
            output.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){
            // no two adjacent elements should be same
            if(!curr.empty() && curr.back() == c) continue;
            curr.push_back(c);
            backTrack(curr,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        backTrack(curr,n);
        return ((k <= (int)output.size()) ? output[k-1] : "");
    }
};