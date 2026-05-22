class Solution {
private:
    inline int sz(int x){
        if(x == 0) return 1;
        int len = 0;
        while(x){
            len++;
            x /= 10;
        }
        return len;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_set<int> st;
        for(int i : arr1){
            st.insert(i);
            while(i){
                st.insert(i/10);
                i /= 10;
            }
        }
        int len = 0;
        for(int i : arr2){
            int x = sz(i);
            if(st.count(i)){
                len = max(len,x);
                continue;
            }
            while(i){
                if(i/10 == 0) break;
                if(st.count(i/10)){
                    len = max(len,sz(i/10));
                }
                i /= 10;
            }
        }
        return len;
    }
};