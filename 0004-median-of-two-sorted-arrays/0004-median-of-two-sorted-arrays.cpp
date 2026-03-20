class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for(int i=0; i<nums1.size(); i++){
            res.push_back(nums1[i]);
        }
        for(int j=0; j<nums2.size(); j++){
            res.push_back(nums2[j]);
        }
        sort(res.begin(), res.end());
        int n = res.size();
        double median = 0.0;
        if(n % 2 == 1){
            median = res[n/2];
        }else{
            median = (res[n/2 - 1]+res[n/2])/2.0;
        }
        return median;
    }
};