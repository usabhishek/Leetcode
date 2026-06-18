class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteHand = minutes * 6;
        double HourHand = hour*30 + (double)(minutes*6) / 12;

        double ans = abs(minuteHand - HourHand);
        return (ans > 180) ? 360-ans : ans;
    }
};