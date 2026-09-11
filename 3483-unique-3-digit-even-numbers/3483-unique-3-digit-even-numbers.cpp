class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int arr[10] = {0};
        int n = digits.size();
        for(int&i : digits) ++arr[i];
        int count{0};
        for(int i{1}; i <= 9; ++i){
            if(!arr[i]) continue;
            --arr[i];
            for(int j{0}; j <= 9; ++j){
                if(!arr[j]) continue;
                --arr[j];
                for(int k{0}; k <= 9; k+=2){
                    if(arr[k] > 0) ++count; 
                }
                ++arr[j];
            }
            ++arr[i];
        }
        return count;
    }
};