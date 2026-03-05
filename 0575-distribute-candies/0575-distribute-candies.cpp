class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> ans;
        int n = candyType.size();
        int ul = n/2;

        for(int i=0; i<n; i++){
            ans.insert(candyType[i]);
        }
        
        int res = ans.size();

        if(ul <= res){
            return ul;
        }
        return res;
    }
};