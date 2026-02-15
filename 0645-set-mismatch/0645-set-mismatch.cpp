class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(), nums.end());

        int duplicate = 0;
        int sum = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                duplicate = nums[i];
            }
        }
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int expected_sum = n*(n+1)/2;
        int ans = (expected_sum - (sum - duplicate));
        return {duplicate, ans};
    }
};