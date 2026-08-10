class Solution {
public:
    bool winnerSquareGame(int n) {
        // int root = sqrt(n);
        // if(root * root == n){
        //     return true;
        // }
        // return false;
        vector<bool> ans(n+1, false);
        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                if(!ans[i-j*j]){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};