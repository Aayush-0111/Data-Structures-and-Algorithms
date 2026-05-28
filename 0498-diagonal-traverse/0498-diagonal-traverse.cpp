class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans,v;
        bool flag = true;
        for(int sum = 0; sum <= m+n-2; sum++){
            for(int i = 0; i < n; i++){
                int j = sum-i;
                if(j < 0 || j > m-1) continue;
                if(flag) v.push_back(mat[i][j]);
                else ans.push_back(mat[i][j]);
            }
            if(flag){
                reverse(v.begin(),v.end());
                for(int& i : v) ans.push_back(i);
                flag = false;
            }else flag = true;
            v.clear();
        }
        
        return ans;
    }
};