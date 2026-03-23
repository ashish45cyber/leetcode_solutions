class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > nums[m]){
                m = i;
            }
        }
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != nums[m] && nums[m] < (2*nums[i])){
                return -1;
            }
            i++;
        }
        return m;
    }
};