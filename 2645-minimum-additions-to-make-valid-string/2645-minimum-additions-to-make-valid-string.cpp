class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int i{0}, j{0}, ans{0};
        while(i < n || j%3 != 0){
            char want = 'a' + j%3;
            if(word[i] == want) ++i;
            else ++ans;
            ++j;
        }
        return ans;
    }
};