class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> res;
        int i = 0;

        for(int num = 1; num<=n && i<target.size(); num++){

            res.push_back("Push");
            if(num == target[i]){
                i++;
            }else{
                res.push_back("Pop");
            }
        }
        return res;
    }
};