class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        int l = to_string(low).length();
        int h = to_string(high).length();

        for(int i=l; i<=h; i++){
            for(int j=0; j+i<=9; j++){
                string temp = s.substr(j, i);
                int n = stoi(temp);

                if(n >= low && n <= high){
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
};