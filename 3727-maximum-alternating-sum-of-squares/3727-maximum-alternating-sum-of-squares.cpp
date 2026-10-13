class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<long long> res(n);
        for(long long i=0; i<n; i++){
            res[i] = nums[i] * nums[i];
        }
        sort(res.begin(), res.end());
        long k = n/2;
        for(int i=0; i<k; i++){
            ans -= res[i];
        }
        for(int i=k; i<n; i++){
            ans += res[i];
        }
        return ans;
    }
};