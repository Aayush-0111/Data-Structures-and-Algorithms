class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                    int top = st.top();
                    if(top > abs(asteroids[i])){
                        asteroids[i] = 0;
                    }else if(top == abs(asteroids[i])){
                        st.pop();
                        asteroids[i] = 0;
                    }else if(top < abs(asteroids[i])){
                        st.pop();
                    }
                }
                if(asteroids[i] != 0) st.push(asteroids[i]);
            
            }else {
                st.push(asteroids[i]);
            }
        } 
        if(!st.empty()){
            while(!st.empty()){
                int x = st.top();
                ans.push_back(x);
                st.pop();
            }
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};