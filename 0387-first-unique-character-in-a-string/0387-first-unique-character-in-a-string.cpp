class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int frq[26] = {0};
        vector<bool> state(26,true);
        queue<int> q;
        for(int i = 0; i < n; i++){
            char c = s[i];
            frq[c-'a']++;
            q.push(i);
            if(frq[c-'a'] != 1){
                while(!q.empty() && frq[s[q.front()]-'a'] > 1) q.pop();
            }
        }
        return (!q.empty()) ? q.front() : -1;
    }
};