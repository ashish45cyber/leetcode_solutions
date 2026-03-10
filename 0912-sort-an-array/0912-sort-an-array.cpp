class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r){
        vector<int>temp;
        int i = l, j = mid+1;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        // elements that left in left half
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        // elements that are left in right half.
        while(j <= r){
            temp.push_back(nums[j]);
            j++;
        }
        //copy into main array or vector
        for(int k=0; k<temp.size(); k++){
            nums[k+l] = temp[k];
        }
    }
    void mergesort(vector<int> &nums, int l, int r){
        if(l < r){
            int mid = l+(r - l)/2;
            mergesort(nums, l, mid);
            mergesort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        mergesort(nums, 0, n-1);
        return nums;
    }
};