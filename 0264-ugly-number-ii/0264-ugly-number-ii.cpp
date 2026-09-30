class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> ugn;
        ugn.insert(1);
        long curr{1};
        for(int i{0}; i < n; ++i){
            curr = *ugn.begin();
            ugn.erase(ugn.begin());
            ugn.insert(curr*2);
            ugn.insert(curr*3);
            ugn.insert(curr*5);
        }
        return (int)curr;
    }
};