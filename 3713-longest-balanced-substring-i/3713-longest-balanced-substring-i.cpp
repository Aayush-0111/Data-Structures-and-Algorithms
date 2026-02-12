class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            vector<int> mp(26,0);
            for(int j = i; j < n; j++){
                mp[s[j]-'a']++;
                int prev = -1;
                bool flag = true;
                for(int x = 0; x < 26; x++){
                    if(mp[x] == 0) continue;
                    else if(prev == -1) prev = mp[x];
                    else if(prev != mp[x]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) continue;
                maxi = max(maxi,j-i+1);
            }
            if(maxi > n-i) break;
        }
        return maxi;
    }
};