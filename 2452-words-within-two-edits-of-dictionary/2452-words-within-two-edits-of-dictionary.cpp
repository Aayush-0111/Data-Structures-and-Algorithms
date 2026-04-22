class Solution {
private:
    bool difference(string& a, string& b){
        int n = a.size(), diff = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]) diff++;
            if(diff > 2) return false;
        }
        return true;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // lowercase english letters
        // same length strings
        int n = queries.size();
        vector<string> ans;
        for(auto& s : queries){
            for(auto& wrd : dictionary){
                if(difference(s,wrd)){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};