class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int a = INT_MAX;
            int b = INT_MIN;
            for(int j=0; j<=i; j++){
                b = max(nums[j], b);
            }
            for(int j=i; j<n; j++){
                a = min(nums[j], a);
            }
            int res = b - a;
            if(res <= k){
                return i;
            }
        }
        return -1;
        // int n = nums.size();
        // vector<int> pmax(n);
        // pmax[0] = nums[0];
        // for(int i=1; i<n; i++){
        //     pmax[i] = max(pmax[i-1], pmax[i]);
        // }
        // vector<int> smin(n);
        // smin[n-1] = nums[n-1];
        // for(int i=n-2; i>=0; i--){
        //     smin[i] = min(smin[i+1], smin[i]);
        // }
        // int i = 0;
        // while(i < pmax.size()){
        //     if(pmax[i] - smin[i] <= k){
        //         return i;
        //     }
        //     i++;
        // }
        // return -1;
    }
};