class Solution {
private:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int,int>> idx(26,{-1,-1});
        for(int i{0}; i < n; ++i){
            char c = s[i];
            if(idx[c-'a'].first == -1){
                idx[c-'a'].first = i;
                idx[c-'a'].second = i;
            }
            else idx[c-'a'].second = i;
        }
        vector<pair<int,int>> intervals;
        for(auto& p : idx){
            if(p.first == -1) continue;
            int l{p.first}, r{p.second};
            bool isValid{true};
            while(l <= r){
                char c = s[l];
                if(idx[c-'a'].first < p.first){
                    isValid = false;
                    break;
                }
                if(idx[c-'a'].second > r) r = idx[c-'a'].second;
                ++l;
            }
            if(isValid) intervals.emplace_back(p.first,r);
        }
        sort(intervals.begin(),intervals.end(),cmp);
        int lastEnd{-1};
        vector<pair<int,int>> selected;
        for(auto& p : intervals){
            if(p.first > lastEnd){
                selected.emplace_back(p);
                lastEnd = p.second;
            }
        }
        vector<string> ans;
        for(auto& p : selected){
            ans.push_back(s.substr(p.first,p.second-p.first+1));
        }
        return ans;
    }
};