/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3390/
 */

class Solution {
public:
  double angleClock(int hour, int minutes) {
    double hourAngle = (hour % 12) * 30 + minutes * 0.5;
    double minuteAngle = minutes * 6;
    double angle = abs(hourAngle - minuteAngle);
    return (angle >= 180) ? 360 - angle : angle;
  }
};
