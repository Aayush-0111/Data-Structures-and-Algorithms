class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int arr[10] = {0};
        int n = digits.size();
        for(int i{0}; i < n; ++i) ++arr[digits[i]];
        int count{0};
        for(int i{100}; i <= 998; i+=2){
            int arr2[10] = {0};
            copy(arr,arr+10,arr2);
            int num{i}; 
            --arr2[num%10];
            if(arr2[num%10] < 0) continue;
            num /= 10;
            --arr2[num%10];
            if(arr2[num%10] < 0) continue;
            num /= 10;
            --arr2[num%10];
            if(arr2[num%10] < 0) continue;
            ++count;
        }
        return count;
    }
};