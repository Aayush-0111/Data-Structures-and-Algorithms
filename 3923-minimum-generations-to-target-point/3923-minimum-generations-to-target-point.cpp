class Solution {
private:
    vector<int> compute(vector<int>& a, vector<int>& b){
        vector<int> c(3,0);
        c[0] = ((a[0]+b[0])/2);
        c[1] = ((a[1]+b[1])/2);
        c[2] = ((a[2]+b[2])/2);
        return c;
    }
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n = points.size();
        if(n == 1) {
            if(points[0] == target) return 0;
            return -1;
        }
        set<vector<int>> st;
        for(auto& i : points){
            if(i == target) return 0;
            st.insert(i);
        }
        vector<vector<int>> all = points;
        int k = 0;
        while(true){
            k++;
            vector<vector<int>> gen;
            int m = all.size();
            for(int i = 0; i < m; i++){
                for(int j = i+1; j < m; j++){
                    if(all[i] == all[j]) continue;
                    auto y = compute(all[i],all[j]);
                    if(st.count(y)) continue;
                    if(y == target) return k;
                    st.insert(y);
                    gen.push_back(y);
                }
            }
            if(gen.empty()) return -1;
            for(auto &i : gen) all.push_back(i);
        }
        return -1;
    }
};