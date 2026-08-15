class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalxor = 0;
        bool hasnonzero = false;
        for(int i : nums){
            totalxor ^= i;
            if(i != 0){
                hasnonzero = true;
            }
        }
        if(totalxor != 0){
            return n;
        }
        if(hasnonzero){
           return n-1;
        }
        return 0;
    }
};