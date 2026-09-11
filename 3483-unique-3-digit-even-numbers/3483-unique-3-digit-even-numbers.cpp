static int arr[1000];
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        memset(arr,0,sizeof(arr));
        int n = digits.size();
        for(int i{0}; i < n; ++i){
            if(!digits[i]) continue;
            for(int j{0}; j < n; ++j){
                if(i == j) continue;
                for(int k{0}; k < n; ++k){
                    if(i == k || j == k) continue;
                    int t = digits[i]*100 + digits[j]*10 + digits[k];
                    if(t%2 == 0) ++arr[t];
                }
            }
        }
        int count{0};
        for(int i{100}; i <= 998; i+=2) if(arr[i]) ++count;
        return count;
    }
};