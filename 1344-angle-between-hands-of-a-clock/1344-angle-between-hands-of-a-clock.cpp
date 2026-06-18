class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleByHr = hour*30 + minutes*(0.5);
        double angleByMin = minutes*6;
        double angleInBw = abs(angleByHr - angleByMin);
        return min(angleInBw,360-angleInBw);
    }
};