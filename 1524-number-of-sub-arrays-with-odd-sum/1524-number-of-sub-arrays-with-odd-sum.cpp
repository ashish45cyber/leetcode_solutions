class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // int n = arr.size();
        // const int MOD = 1e9 + 7;
        // int count = 0;
        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum += arr[j];
        //         if(sum % 2 != 0){
        //             count = (count + 1) % MOD;
        //         }
        //     }
        // }
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int even = 1, odd = 0, count = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                count = (count + odd) % MOD;
                even++;
            }else{
                count = (count + even) % MOD;
                odd++;
            }
        }
        return count;
    }
};