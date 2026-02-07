class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        vector<string> num;
        int i = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                string t = "";
                while(i < n && s[i] >= '0' && s[i] <= '9'){
                    t += s[i++];
                }
                num.push_back(t);
            }
            else i++;
        }
        for(string t : num) cout << t << " ";
        for(int i = 1; i < (int)num.size(); i++){
            if(stoi(num[i-1]) >= stoi(num[i])) return false;
        }
        return true;
    }
};