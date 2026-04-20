class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        int j = n-1, maxi = arr[n-1];
        while(j >= 1){
            maxi = max(maxi,arr[j]);
            ans[j-1] = maxi;
            j--;
        }
        return ans;
    }
};