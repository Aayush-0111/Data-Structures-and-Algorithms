class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.size(), sum = 0;
        int frq1[26];
        int frq2[10];
        for(char& c : s){
           if(isalpha(c)) frq1[c-'a']++;
           else frq2[c-'0']++;
        }
        // as we already have all the characters in the string inside frq arrays
        // just use them instead of manually looping over the string again
        for(int i = 0; i < 13; i++){
            sum += abs(frq1[i] - frq1[25-i]);
        }
        for(int i = 0; i < 5; i++){
            sum += abs(frq2[i] - frq2[9-i]);
        }
        return sum;
    }
};