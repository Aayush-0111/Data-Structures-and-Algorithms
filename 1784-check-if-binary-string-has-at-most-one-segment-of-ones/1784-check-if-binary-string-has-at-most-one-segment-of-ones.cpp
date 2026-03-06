class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size(), cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                while(i < n){
                    if(s[i] != '1') break;
                    i++;
                }
                cnt1++;
            }
        }
        return (cnt1 == 1);
    }
};