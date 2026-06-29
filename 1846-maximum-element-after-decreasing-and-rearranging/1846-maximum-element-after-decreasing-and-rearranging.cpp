class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1,0);
        for(int& i : arr) count[min(i,n)]++;
        int ans = 1;
        for(int num = 2; num <= n; num++){
            // ans+count[num] <= num ([1,2,3,100,100,100])
            // for num = 100 and ans = 3, there 97 spots in the range [4,100], so we can't fill all the spots
            // but we can just take all the occurenceso of 100(num) and reduce them to fill spots like 4,5,6....
            
            // ans + count[num] > num ([1,2,3,3,3,3])
            // for num = 3 and ans = 2, we have more occurences of 3 than there are spots b/w 2 and 3.
            // so our ans will just be num of this entire count[num] block ([3,3,3,3]).
            
            // both these conditions can be sumarized using this:
            ans = min(ans+count[num],num); 
            // as in 1st condition, ans is simply adding count[num] to the ans and in second condition
            // ans is simply num. Which condition is valid is determined by whichever is lesser.
        }
        return ans;
    }
};