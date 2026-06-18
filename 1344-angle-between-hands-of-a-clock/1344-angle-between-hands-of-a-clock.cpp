class Solution {
public:
    double angleClock(int hour, int minutes) {
        int minh = 0;
        double hourh = 0;
        if(hour < 12){
            minh = minutes * 6;
            hourh = hour * 30 + minutes * 0.5;
        }else{
            hour = 0;
            minh = minutes * 6;
            hourh = hour + minutes * 0.5;
        }
        double diff = abs(minh - hourh);
        if(diff >= 180){
            diff = 360 - diff;
        }
        return diff;
    }
};