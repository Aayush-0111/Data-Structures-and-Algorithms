class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size(), sum = 0;
        stack<int> st;
        for(string& s : operations){
            if(s != "+" && s != "D" && s != "C"){
                if(s.size() == 1){
                    st.push(s[0]-'0');
                }else if(s.size() > 1 && s[0] == '-'){
                    string t = s.substr(1,s.size()-1);
                    int x = stoi(t);
                    st.push(-1*x);
                }else if(s.size() > 1 && s[0] != '-'){
                    int x = stoi(s);
                    st.push(x);
                }
            }else if(s == "+"){
                int x = 2, sum = 0;
                int a[2] = {0};
                while(!st.empty() && x--){
                    int top = st.top();
                    sum += top;
                    a[x] = top;
                    st.pop();
                }
                st.push(a[0]);
                st.push(a[1]);
                st.push(sum);
            }else if(s == "D"){
                if(!st.empty()){
                    int top = st.top();
                    top *= 2;
                    st.push(top);
                }
            }else if(s == "C"){
                if(!st.empty()) st.pop();
            }
        }
        while(!st.empty()){
            int top = st.top();
            sum += top;
            st.pop();
        }
        return sum;
    }
};