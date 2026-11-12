class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1;
        int declen = 1, inclen = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i+1] > nums[i]){
                inclen++;
                declen = 1;
            }else if(nums[i+1] < nums[i]){
                declen++;
                inclen = 1;
            }else{
                declen = 1;
                inclen = 1;
            }
           maxlen = max( maxlen, max(inclen, declen));
        }
        return maxlen;

    }
};