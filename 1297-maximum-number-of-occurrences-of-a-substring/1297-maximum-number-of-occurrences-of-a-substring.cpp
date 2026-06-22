class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        unordered_map<string,int> frq1; // for substring
        unordered_map<char,int> frq2;   // for unique chars
        // we choose the substring of length minsize
        // if we have a valid substring, we increment it's count in the map
        // this window will run till the end of the string and at the end
        // we will iterate the map(containg all valid subtrings) and return
        // maximum value.
        // choosing a substring greater than minSize substring and satifysing the constraints mean
        // selected susbtring will contain the minsize substring and it will have atleast frequency
        // of bigger substring. And since, smaller substing have larger frequency, checking for minSize
        // substrings will suffice.
        int start = 0, ans = 0;
        for(int i = 0; i < n; i++){
            frq2[s[i]]++;
            if(i-start+1 > minSize){
                frq2[s[start]]--;
                if(frq2[s[start]] == 0) frq2.erase(s[start]);
                start++;
            }
            if(i-start+1 == minSize && frq2.size() <= maxLetters){
                ans = max(ans,++frq1[s.substr(start,i-start+1)]);
            }
        }
        return ans;
    }
};