class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(arr[mid] < x){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        vector<int> res;
        int right = l;
        int left = l - 1;

        while (k--) {

            if (left < 0) {
                res.push_back(arr[right]);
                right++;
            }
            else if (right >= n) {
                res.push_back(arr[left]);
                left--;
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                res.push_back(arr[left]);
                left--;
            }
            else {
                res.push_back(arr[right]);
                right++;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};