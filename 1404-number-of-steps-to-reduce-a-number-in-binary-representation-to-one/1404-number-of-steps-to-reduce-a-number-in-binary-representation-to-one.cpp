class Solution {
private:
    string add1toBinary(string s){
        int n = s.size()-1;
        while(n >= 0 && s[n] == '1'){
            s[n] = '0'; 
            n--;
        }
        if(n >= 0){
            s[n] = '1';
        }else{
            // 1 overflowed, so add it in front
            s = '1' + s;
        }
        return s;
    }
public:
    int numSteps(string s) {
        int n = s.size(), count = 0;
        while(s != "1"){
            if(s.back() != '1'){
                s.pop_back();
            }else{
                s = add1toBinary(s);
            }
            count++;
        }
        return count;
    }
};