class Solution {
private:
    static bool cmp(int a, int b){
        int num1 = __builtin_popcount(a);
        int num2 = __builtin_popcount(b);
        if(num1 == num2) return a < b;
        return num1 < num2;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};