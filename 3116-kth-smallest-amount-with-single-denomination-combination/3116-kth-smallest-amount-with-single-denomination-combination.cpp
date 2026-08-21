#define ll long long
class Solution {
private:
    ll gcd(ll a, ll b){
        while(b){
            ll r = a%b;
            a = b;
            b = r;
        }
        return a;
    }
    ll lcm(ll a, ll b){
        return (a/gcd(a,b))*b;
    }
    ll count(ll x, vector<int>& coins){
        int n = coins.size();
        ll ans = 0;
        for(int mask{1}; mask < (1 << n); ++mask){
            ll L{1};
            int bits{0};
            bool valid = true;
            for(int i{0}; i < n; ++i){
                if(mask & (1 << i)){
                    ++bits;
                    L = lcm(L,(ll)coins[i]);
                    if(L > x){
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid) continue;
            if(bits&1) ans += x/L;
            else ans -= x/L;
        }
        return ans;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // First remove redundant coins like if there is {2,6} here 6 is redundant
        // cause every amount produced by 6 will be produced by 6, so we don't need 6.
        sort(coins.begin(),coins.end());
        vector<int> newCoins;
        for(int& x : coins){
            bool redundant = false;
            for(int& y : newCoins){
                if(x%y == 0){
                    redundant = true;
                    break;
                }
            }
            if(!redundant) newCoins.push_back(x);
        }
        coins = newCoins;
        ll low{1};
        // high is smallest coin*k cause it independently can produce c,2c,3c,,,kc amounts
        // so including the contribution of ohter coins, kth smallest amount will be <= it.
        ll high = (ll)*min_element(coins.begin(),coins.end())*k;
        // here we are counting the first valid count(x) cause only that will be an achievable no,
        // ex: 2,4,5,6,8,10,12,14,15 -> now count(12) == 7 but also count(13) == 7 but 13 is not
        // an achievable amount so we cannot condider it. therefore first amount satisfying
        // count(x) >= k.
        while(low < high){
            ll mid{low + (high-low)/2};
            if(count(mid,coins) >= k) high = mid;
            else low = mid+1;
        }
        return low; 
    }
};