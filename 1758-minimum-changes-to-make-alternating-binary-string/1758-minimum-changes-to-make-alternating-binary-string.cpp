class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                flag = false;
                break;
            }
        }
        if(flag) return 0;
        string fin1 = "1";
        string fin2 = "0";
        for(int i = 1; i < n; i++){
            if(fin1[i-1] == '1'){
                fin1 += '0';
            }else if(fin1[i-1] == '0'){
                fin1 += '1';
            }
            if(fin2[i-1] == '1'){
                fin2 += '0';
            }else{
                fin2 += '1';
            }
        }
        int ops1 = 0, ops2 = 0;
        for(int i = 0; i < n; i++){
            if(fin1[i] != s[i]) ops1++;
            if(fin2[i] != s[i]) ops2++;
        }
        return min(ops1,ops2);
    }
};