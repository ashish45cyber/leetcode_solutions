class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i]+nums[j] == 0){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};