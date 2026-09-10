class Solution {
public:
    bool search(vector<int>& nums, int target) {
        while(find(nums.begin(), nums.end(), target) != nums.end()){
            return true;
        }
        return false;
    }
};