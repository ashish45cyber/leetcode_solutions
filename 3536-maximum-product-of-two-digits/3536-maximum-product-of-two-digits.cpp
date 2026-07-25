class Solution {
public:
    int maxProduct(int n) {
        int firstmax = 0;
        int secondmax = 0;
        while(n > 0){
            int digit = n % 10;
            if(digit >= firstmax){
                secondmax = firstmax;
                firstmax = digit;
            }
            else if(digit > secondmax ){
                secondmax = digit;
            }
            n /= 10;
        }
        return firstmax*secondmax;
    }
};