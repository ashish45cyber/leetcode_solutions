class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxjump = 0, jumps = 0, lastidx = 0;

        for(int i=0; i<n-1; i++){
         maxjump = max(maxjump, nums[i]+i);
            if(i == lastidx){
                jumps++;
                lastidx = maxjump;
            }
        }
        return jumps;
    }
};