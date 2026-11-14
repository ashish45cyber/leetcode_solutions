class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                int len = j-i+1;
                if(len >= l && len <= r && sum > 0){
                    min_sum = min(min_sum, sum);
                }
            }
        }
        if(min_sum == INT_MAX){
            return -1;
        }
        return min_sum;
    }
};