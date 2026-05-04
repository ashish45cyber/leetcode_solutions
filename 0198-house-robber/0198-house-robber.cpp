class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        if(n == 1){
            return nums[0];
        }
        if(n < 2){
            return max(nums[0], nums[1]);
        }
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            int sum = max(b, a+nums[i]);
            a = b;
            b = sum;
        }
        return b;
    }
};