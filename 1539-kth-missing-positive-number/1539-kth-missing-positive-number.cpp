class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, num = 1;

        while(true){
            if(i<n && arr[i] == num){
                i++;
            }else{
                k--;
                if(k == 0){
                    return num;
                }
            }
            num++;
        }
    }
};