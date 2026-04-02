class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, n = directions.size();
        stack<char> st;
        for(char c : directions){
            if(c == 'R') st.push(c);
            else if(c == 'S'){
                if(st.empty()) st.push(c);
                else if(!st.empty() && st.top() == 'R'){
                    while(!st.empty() && st.top() == 'R'){
                        ans++;
                        st.pop();
                    }
                    if(st.empty()) st.push(c);
                }
            }else if(c == 'L') {
                if(!st.empty() && st.top() == 'R'){
                    ans+= 2;
                    st.pop();
                    while(!st.empty() && st.top() == 'R'){
                        ans++;
                        st.pop();
                    }
                    if(st.empty()) st.push('S');
                }else if(!st.empty() && st.top() == 'S') ans++;
            }
        }
        return ans;
    }
};