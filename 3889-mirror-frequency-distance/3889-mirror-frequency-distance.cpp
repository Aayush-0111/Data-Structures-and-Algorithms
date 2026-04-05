class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size(), sum = 0;
        vector<int> frq1(26);
        vector<int> frq2(10);
        for(char& c : s){
           if(isalpha(c)) frq1[c-'a']++;
           else frq2[c-'0']++;
        }
        for(char& c : s){
            if(isalpha(c)){
                sum += abs(frq1[c-'a'] - frq1['z'-c]);
                frq1[c-'a'] = 0;
                frq1['z'-c] = 0;
            }else{
                sum += abs(frq2[c-'0'] - frq2['9'-c]);
                frq2[c-'0'] = 0;
                frq2['9'-c] = 0;
            }
        }
        return sum;
    }
};