class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        string ans{s};
        while(ans.size() > k){
            int cnt{0}, sum{0};
            string temp{""};
            for(char& c : ans){
                ++cnt;
                sum += c-'0';
                if(cnt == k){
                    cnt = 0;
                    temp += to_string(sum);
                    sum = 0;
                }
            }
            if(cnt) temp += to_string(sum);
            ans = temp;
        }
        return ans;
    }
};