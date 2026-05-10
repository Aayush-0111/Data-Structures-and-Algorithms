class Solution {
private:
    bool isLower(char& a){
        return (a >= 'a' && a <= 'z');
    }
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        int n = queries.size();
        vector<int> ans(n,0);
        string s;
        for(auto& a : chunks) s += a;
        int m = s.size();
        unordered_map<string,int> mp;
        string cur = "";
        for(int i = 0; i < m; i++){
            char c = s[i];
            if(isLower(c)){
                cur += c;
            }else if(c == '-'){
                if(cur.size() != 0 && i+1 < m && isLower(s[i+1])){
                    cur += c;
                }else {
                    if(cur.size() != 0){
                        mp[cur]++;
                        cur = "";
                    }
                    
                }
            }else{
                if(cur.size() != 0){
                    mp[cur]++;
                    cur = "";
                } 
            }
        }
        if(cur.size() != 0) mp[cur]++;
        for(int i = 0; i < n; i++){
            if(mp.count(queries[i])){
                ans[i] = mp[queries[i]];
            }
        }
        return ans;
    }
};