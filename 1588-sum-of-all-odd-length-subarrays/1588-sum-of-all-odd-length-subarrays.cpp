class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        for(int i{0}; i < n-1; ++i){
            int currSum{arr[i]};
            for(int j{i+1}; j < n; ++j){
                currSum += arr[j];
                if((j-i+1)%2) sum += currSum;
            }
        }
        return sum;
    }
};