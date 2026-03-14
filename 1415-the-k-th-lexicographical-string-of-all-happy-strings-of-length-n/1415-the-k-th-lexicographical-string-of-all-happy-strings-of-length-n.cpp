class Solution {
public:
    vector<string> output;
    int x;
    void backTrack(string& curr, int n, int k){
        if((int)curr.size() == n){
            output.push_back(curr);
            x++;
            return;
        }
        if(x == k) return;
        for(char c : {'a','b','c'}){
            // no two adjacent elements should be same
            if(!curr.empty() && curr.back() == c) continue;
            curr.push_back(c);
            backTrack(curr,n,k);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        x = 0;
        string curr = "";
        backTrack(curr,n,k);
        return ((k <= (int)output.size()) ? output[k-1] : "");
    }
};