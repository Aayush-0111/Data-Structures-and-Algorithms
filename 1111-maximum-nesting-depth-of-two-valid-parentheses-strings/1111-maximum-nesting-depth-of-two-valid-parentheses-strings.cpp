class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        stack<char> st;
        vector<int> depth;
        depth.reserve(n);
        for(char& c : seq){
            if(c == '('){
                st.push(c);
                depth.push_back(st.size());
            }else{
                depth.push_back(st.size());
                st.pop();
            } 
        }
        vector<int> ans;
        ans.reserve(n);
        for(int i{0}; i < n; ++i){
            if(depth[i]%2 == 0) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};