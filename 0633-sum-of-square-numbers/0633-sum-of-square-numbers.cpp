class Solution {
public:
    bool judgeSquareSum(int c) {
        long  s = 0, e = sqrt(c);
        while(s <= e){
           long sum = s*s + e*e;
           if(sum == c){
            return true;
           }else if(sum < c){
            s++;
           }else{
            e--;
           }
        }
        return false;
    }
};