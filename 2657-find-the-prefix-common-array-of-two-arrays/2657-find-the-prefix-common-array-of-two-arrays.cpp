class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), cnt = 0;
        vector<bool> check1(n+1,false), check2(n+1,false);
        vector<int> ans(n,0);
        ans[n-1] = n;
        for(int i = 0; i < n-1; i++){
            if(A[i] == B[i]) {
                cnt++;
            }else {
                if(check2[A[i]]) cnt++;
                if(check1[B[i]]) cnt++;
            }
            ans[i] = cnt;
            check1[A[i]] = true;
            check2[B[i]] = true;
        }
        return ans;
    }
};