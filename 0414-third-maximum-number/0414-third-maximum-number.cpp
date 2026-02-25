class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int count = 1;
        int max = nums[0];
        int ans = 0;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != max){
                count++;
                max = nums[i];
            }
            if(count == 3){
                ans = max;
                return ans;
            }
        }
         return nums[0];
    }
};