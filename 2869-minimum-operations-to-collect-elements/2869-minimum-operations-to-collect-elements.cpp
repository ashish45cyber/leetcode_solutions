class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        unordered_set<int> collection;
        int op_count = 0;

        for(int i = nums.size()-1; i>=0; i--){
            op_count++;
            if(nums[i] <= k){
                collection.insert(nums[i]);
            }
            if(collection.size() == k){
                return op_count;
            }
        }
        return op_count;
    }
};