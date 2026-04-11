class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, a = INT_MAX;
        int pos;
        if(n<3){
            return 0;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    sum = nums[i]+nums[j]+nums[k];
                    int b = target - sum;
                    if(b<0){
                        b = -1*b;
                    }
                    if(b<a){
                        a=b;
                        pos = sum;
                    }
               }
            }
        }
        return pos;
    }
};