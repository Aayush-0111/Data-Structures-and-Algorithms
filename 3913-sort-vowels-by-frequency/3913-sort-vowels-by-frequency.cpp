class Solution {
private:
    static bool cmp(pair<char,pair<int,int>>& a, pair<char,pair<int,int>>& b){
        if(a.second.first == b.second.first) return a.second.second < b.second.second;
        return (a.second.first > b.second.first);
    }
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<pair<char,pair<int,int>>> p(5);
        vector<int> idx;
        p[0].first = 'a'; p[1].first = 'e'; p[2].first = 'i'; p[3].first = 'o'; p[4].first = 'u';
        p[0].second.second = -1; p[1].second.second = -1; p[2].second.second = -1; p[3].second.second = -1; p[4].second.second = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' ){
                p[0].second.first++;
                if(p[0].second.second == -1){
                    p[0].second.second = i;
                }
                idx.push_back(i);
            }
            else if(s[i] == 'e' ){
                p[1].second.first++;
                if(p[1].second.second == -1){
                    p[1].second.second = i;
                }
                idx.push_back(i);
            }
            else if(s[i] == 'i' ){
                p[2].second.first++;
                if(p[2].second.second == -1){
                    p[2].second.second = i;
                }
                idx.push_back(i);
            }
            else if(s[i] == 'o' ){
                p[3].second.first++;
                if(p[3].second.second == -1){
                    p[3].second.second = i;
                }
                idx.push_back(i);
            }
            else if(s[i] == 'u' ){
                p[4].second.first++;
                if(p[4].second.second == -1){
                    p[4].second.second = i;
                }
                idx.push_back(i);
            }
        }
        sort(p.begin(),p.end(),cmp);
        
        int x = 0;
        for(int &i : idx){
            if(p[x].second.first == 0 && x <= 4) x++;
            s[i] = p[x].first;
            p[x].second.first--;
        }
        return s;
    }
};