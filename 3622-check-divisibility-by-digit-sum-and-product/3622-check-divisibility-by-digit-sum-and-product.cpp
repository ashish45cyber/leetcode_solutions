class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int dsum = 0;
        while(n > 0){
            int digit = n%10;
            dsum += digit;
            n /= 10;
        }
        int dproduct = 1;
         n = num;
        while(n > 0){
            int digit = n%10;
            dproduct *= digit;
            n /= 10;
        }
        if(num % (dsum + dproduct) == 0){
            return true;
        }
        return false;
    }
};