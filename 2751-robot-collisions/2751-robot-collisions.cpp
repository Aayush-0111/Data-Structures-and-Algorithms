class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> survivors, indices(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(),indices.end(),[&](int l, int r){
            return positions[l] < positions[r];
        });
        for(int curridx : indices){
            if(directions[curridx] == 'R') s.push(curridx);
            else{
                while(!s.empty() && healths[curridx] > 0){
                    int x = s.top();
                    s.pop();
                    if(healths[x] > healths[curridx]){
                        healths[curridx] = 0;
                        healths[x]--;
                        s.push(x);
                    }else if(healths[x] == healths[curridx]){
                        healths[x] = 0;
                        healths[curridx] = 0;
                    }else{
                        healths[x] = 0;
                        healths[curridx]--;
                    }
                }
            }
        }
        // collecting survivors
        for(int i = 0; i < n; i++){
            if(healths[i] > 0) survivors.push_back(healths[i]);
        }
        return survivors;
    }
};