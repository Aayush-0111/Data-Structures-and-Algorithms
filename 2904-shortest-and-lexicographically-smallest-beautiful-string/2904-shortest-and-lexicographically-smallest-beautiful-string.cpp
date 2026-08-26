class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        if(ranges::count(s,'1') < k) return "";
        string ans = "";
        int i{0}, count{0}, l{0};
        while(i < n && count != k){
            if(s[i++] == '1') ++count;
            if(s[l] == '0') ++l;
        }
        if(i == n && count != k) return ""; 
        ans = s.substr(l,i-l);
        for(int r{i}; r < n; ++r){
            count += (s[r] == '1') ? 1 : 0;
            while(l < n && (count > k || s[l] == '0')){
                count -= s[l] == '1' ? 1 : 0;
                ++l;
            }
            //cout << l << " ";
            if(count == k){
                string temp = s.substr(l,r-l+1);
                if(temp.size() < ans.size()) ans = temp;
                else if(temp.size() == ans.size() && temp < ans) ans = temp;
            }
        }
        return ans;
    }
};