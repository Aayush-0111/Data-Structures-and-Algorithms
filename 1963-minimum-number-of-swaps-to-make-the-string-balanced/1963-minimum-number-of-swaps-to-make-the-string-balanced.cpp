class Solution {
public:
    int minSwaps(string s) {
        int cnt1{0}, cnt2{0};
        for(char& c : s){
            if(c == '[') ++cnt1;
            else{
                !cnt1 ? ++cnt2 : --cnt1;
            }
        }
        return (cnt2+1)/2;
    }
};