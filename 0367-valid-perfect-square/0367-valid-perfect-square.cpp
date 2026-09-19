class Solution {
public:
    long square_root(int n){
        if(n < 2) return n;
        long long l = 1, r = n;
        while(l <= r){
            long long mid = l+(r-l)/2;
            if(mid * mid == n){
                return mid;
            }else if(mid * mid < n){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
    bool isPerfectSquare(int num) {
        long long ans = square_root(num);
        if(ans * ans == num){
            return true;
        }
        return false;
    }
};