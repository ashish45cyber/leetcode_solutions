class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.length()){
            return false;
        }
        for(int i=0; i<n; i++){
            string s2 = s.substr(i) + s.substr(0, i);
            if(s2 == goal){
                return true;
            }
        }
        return false;
    }
};