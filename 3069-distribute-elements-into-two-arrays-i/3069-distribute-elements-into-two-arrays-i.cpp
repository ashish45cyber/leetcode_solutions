class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a1 = {nums[0]};
        vector<int> a2 = {nums[1]};
        for(int i=2; i<n; i++){
            if(a1.back() > a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
        }
        vector<int> res = {a1.begin(), a1.end()};
        for(int i=0; i<a2.size(); i++){
            res.push_back(a2[i]);
        }
        return res;
    }
};