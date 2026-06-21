class Solution {
private:
    void countingSort(vector<int>& arr){
        int n = arr.size();
        int maxi = *max_element(arr.begin(),arr.end());
        vector<int> cntArr(maxi+1,0), ans(n,0);
        // frq array
        for(int& i : arr) cntArr[i]++;
        // prefix sum
        for(int i = 1; i <= maxi; i++) cntArr[i] += cntArr[i-1];
        // sorted array
        for(int i = n-1; i >= 0; i--){
            ans[cntArr[arr[i]]-1] = arr[i];
            cntArr[arr[i]]--;
        }
        arr = ans;
    }
public:
    int maxIceCream(vector<int>& costs, int coins) {
        countingSort(costs);
        int maxi = 0;
        for(int& i : costs){
            coins -= i;
            if(coins < 0) return maxi;
            maxi++;
        }
        return maxi;
    }
};