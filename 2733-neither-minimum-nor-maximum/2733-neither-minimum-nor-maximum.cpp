class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int min = nums[0];
        int max = nums[n-1];
        int ans = 0;

        for(int i=1; i<n-1; i++){
            if(nums[i] < max && nums[i] > min){
                ans = nums[i];
                return ans;
                break;
            }
        }
        return -1;
    }
};