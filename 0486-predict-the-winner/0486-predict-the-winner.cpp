class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0){
            return true;
        }
        vector<vector<int>> ans(n, vector<int>(n, -1));
        return maxdiff(nums, 0, n-1, ans) >= 0;
    }
    int maxdiff(vector<int>&nums, int l, int r, vector<vector<int>> &ans){
        if(l == r){
            return nums[l];
        }
        if(ans[l][r] != -1){
            return ans[l][r];
        }
        int a = nums[l] - maxdiff(nums, l+1, r, ans);
        int b = nums[r] - maxdiff(nums, l, r-1, ans);
        return ans[l][r] = max(a, b);
    }
};