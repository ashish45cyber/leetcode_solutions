class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxidx = max_element(nums.begin(), nums.end()) - nums.begin();

        int m1 = max(maxidx, minidx);
        int m2 = min(minidx, maxidx);

        int a = m1+1;
        int b = n-m2;
        int c = (m2+1) + (n-m1);

        return min({a,b,c});
    }
};