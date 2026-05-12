class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int frq[26] = {0};
        queue<int> q;
        for(int i = 0; i < n; i++){
            char c = s[i];
            frq[c-'a']++;
            q.push(i);
            while(!q.empty() && frq[s[q.front()]-'a'] > 1) q.pop();
        }
        return (!q.empty()) ? q.front() : -1;
    }
};