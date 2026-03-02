class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();
        int ans = 0;
        stack<int> s;

        for(int i=0; i<n; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(stoi(tokens[i]));
            }else{
                int b = s.top(); 
                s.pop();
                int a = s.top();
                s.pop();

                if(tokens[i] == "+"){
                    s.push(a+b);
                }else if(tokens[i] == "-"){
                    s.push(a-b);
                }else if(tokens[i] == "*"){
                    s.push(a*b);
                }else if(tokens[i] == "/"){
                    s.push(a/b);
                }
            }
        }
        ans = s.top();
        return ans;
    }
};