#define ll long long
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();
        ll ans = 0;
        unordered_map<int,int> mp, h;
        // sorting to avoid duplicate easily
        sort(planks.begin(),planks.end());
        for(int& i : planks) ++mp[i];
        for(int i = 0; i < n; i++){
            if(i+1<n && planks[i] == planks[i+1]) continue;
            // two same height blocks having height == x can generate width of (frq of planks[i])/2
            // multiple distinct blocks can amount to same height, so aggreagte them all.
            h[planks[i]+planks[i]] += mp[planks[i]]/2;
            for(int j = i+1; j < n; j++){
                if(j+1<n && planks[j] == planks[j+1]) continue;
                // two diff height blocks can be merged to form width equal min(frq(block1),frq(block2))
                // diff blocks having diff height can be merged to form a same height(1+4,2+3), so sum them all.
                h[planks[i] + planks[j]] += min(mp[planks[i]],mp[planks[j]]);
            }
        }
        for(auto& it : mp){
            ll f = it.first, s = it.second;
            ll total = h[f] + s;
            ans = max(ans,total);
        }
        for(auto& it : h){
            ll f = it.first, s = it.second;
            ll total = mp[f] + s;
            ans = max(ans,total);
        }
        return ans;
    }
};