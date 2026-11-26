class Solution {
public:
    bool canAliceWin(int n) {
       int a = 10, m = 0;
       while(n >= a){
           n -= a;
           a--;
           m++;
       }
       if(m % 2 == 1){
        return true;
       }
       return false;
    }
};