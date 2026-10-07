class Solution {
private:
    int minimum_count(string& s){
        int cnt1{0}, cnt2{0};
        for(char& c : s){
            if(c == '(') ++cnt1;
            else if(c == ')') !cnt1 ? ++cnt2 : --cnt1;
        }
        return cnt1+cnt2;
    }
    void solve(unordered_set<string>& unq, string& s, string& curr, int i, int l_cnt, int r_cnt, int rem_cnt, int min_rem){
        if(i == s.size()){
            if(l_cnt == r_cnt && rem_cnt == min_rem) unq.insert(curr);
            return;
        }
        if(rem_cnt > min_rem) return;
        char c{s[i]};
        if(c == '('){
            // take it
            curr += s[i];
            solve(unq,s,curr,i+1,l_cnt+1,r_cnt,rem_cnt,min_rem);
            // leave it
            curr.pop_back();
            solve(unq,s,curr,i+1,l_cnt,r_cnt,rem_cnt+1,min_rem);
        }else if(c == ')'){
            if(l_cnt < r_cnt+1){
                solve(unq,s,curr,i+1,l_cnt,r_cnt,rem_cnt+1,min_rem);
                return;
            }
            // take it
            curr += s[i];
            solve(unq,s,curr,i+1,l_cnt,r_cnt+1,rem_cnt,min_rem);
            // leave it
            curr.pop_back();
            solve(unq,s,curr,i+1,l_cnt,r_cnt,rem_cnt+1,min_rem);
        }else{
            curr += s[i];
            solve(unq,s,curr,i+1,l_cnt,r_cnt,rem_cnt,min_rem);
            // this is necessary, cause when this call returns to it's parent call, it will contain letter
            // this is a problem cause when the parent call will try the "leave it" path, it might still contain letters from ahead from their current index. This can corrupt the o/p.
            curr.pop_back();
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int min_removals{minimum_count(s)};
        if(!min_removals) return {s};
        cout << "min_rem = " << min_removals << '\n';
        string curr{""};
        unordered_set<string> unq;
        solve(unq,s,curr,0,0,0,0,min_removals);
        if(unq.empty()) return {""};
        vector<string> ans;
        for(auto& x : unq) ans.push_back(x);
        return ans;
    }
};