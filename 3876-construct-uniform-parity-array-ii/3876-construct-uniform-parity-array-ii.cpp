class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mino = INT_MAX;
        for(int i: nums1){
            if(i % 2 != 0){
                mino = min(mino, i);
            }
        }
        for(int i: nums1){
            if(i % 2 == 0 && mino != INT_MAX && i < mino){
                return false;
            }
        }
        return true;
    }
};