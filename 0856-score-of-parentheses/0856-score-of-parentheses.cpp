class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int score = 0;
        for(char c : s){
            if(c == '('){
                st.push(0);
            }else{
                int a = st.top();
                st.pop();
                if(a == 0){
                    score = 1;
                }else{
                    score = 2*a;
                }
                st.top() += score;
            }
        }
        return st.top();
    }
};